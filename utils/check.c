/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:39:24 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/18 16:40:34 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <../libft/libft.h>

char    *ft_cmd_path(char *cmd, char **envp)
{
    int     i;
    char    *cmd_path;
    char    **split_path;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            split_path = ft_split(envp[i], ':');
        i++;
    }
    i = 0;
    while (split_path[i])
    {
        cmd_path = ft_strjoin(split_path[i], "/");
        cmd_path = ft_strjoin(cmd_path, cmd);
        if (access(cmd_path, F_OK | X_OK) == 0)
            return (cmd_path);
        free(cmd_path);
        cmd_path = NULL;
        i++;
    }
    return (NULL);    
}

void    ft_cmd_exec(t_pipex *data, char **argv, char **envp)
{
    char    **cmd;
    char    *cmd_path;

    cmd = ft_split(argv[data->i], ' ');
    cmd_path = ft_cmd_path(cmd[0], envp);
    if (execve(cmd_path, cmd, envp) == -1)
        ft_print_error("execve error\n");
}

void    ft_last_cmd(t_pipex *data, char **argv, char **envp)
{
    data->outfile_fd = open(argv[data->nb_argc - 1], O_WRONLY | O_APPEND);
    if (data->outfile_fd == -1)
        ft_print_error("outfile open error\n");
    if (dup2(data->outfile_fd, STDOUT_FILENO) == -1);
        ft_print_error("dup2 error\n");
    close(data->outfile_fd);
}

void    ft_first_cmd(t_pipex *data, char **argv, char **envp)
{
    data->infile_fd = open(argv[2], O_RDONLY);
    if (data->infile_fd == -1)
        ft_print_error("infile open error\n");
    if (dup2(data->infile_fd, STDIN_FILENO) == -1)
        ft_print_error("dup2 error\n");
    close(data->infile_fd);
    ft_cmd_exec(data, argv, envp);
}

void    ft_child_process(t_pipex *data, char **argv, char **envp)
{
    close(data->p_fd[READ]);
    if (data->i == 2)
        ft_first_cmd(data, argv, envp);
    else if (data->i == data->nb_argc - 2)
        ft_last_cmd(data, argv, envp);
    if (dup2(data->p_fd[WRITE], STDOUT_FILENO) == -1);
        ft_print_error("dup2 error\n");
    close(data->p_fd[1]);
    ft_cmd_exec(data, argv, envp);
}



void    ft_cmd_process(t_pipex *data, char **argv, char **envp)
{
    pid_t   fork_p;

    if (pipe(data->p_fd) == -1)
        ft_print_error("pipe error\n");
    fork_p = fork();
    if (fork_p < 0)
        ft_print_error("fork error\n");
    if (fork_p == 0)
        ft_child_process(data, argv, envp);
    
}

void    ft_pipex(t_pipex *data, char **argv, char **envp)
{
    data->i = 2;
    while (data->i <= data->nb_argc - 2)
    {
        ft_cmd_process(data, argv, envp);
        data->i++;
    }
    
}


bool    ft_check(int argc, char **argv)
{
    int i;

    i = 2;
    while (i < argc - 1)
    {
        if (argv[i][0] == '\0')
            return (false);
        i++;
    }
    return (true);
}
