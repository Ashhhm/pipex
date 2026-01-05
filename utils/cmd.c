/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:56:56 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/05 06:43:20 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
#include "../libft/libft.h"

char	*ft_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	*cmd_path;
	char	*cmd_path_b;
	char	**split_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			split_path = ft_split(envp[i], ':');
		i++;
	}
	i = -1;
	while (split_path[++i])
	{
		cmd_path_b = ft_strjoin(split_path[i], "/");
		cmd_path = ft_strjoin(cmd_path_b, cmd);
		free(cmd_path_b);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		cmd_path = NULL;
	}
	ft_free_split(split_path);
	return (NULL);
}

void	ft_exec_cmd(t_pipex *data, char *argv, char **envp)
{
	char	**cmd;
	char	*cmd_path;

	cmd = NULL;
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], F_OK | X_OK) == 0)
		{
			if (execve(cmd[0], cmd, envp) == -1)
    		{
				ft_free_split(cmd);
        		ft_print_error("cmd exe error\n");
    		}	
		}
	cmd_path = ft_cmd_path(cmd[0], envp);
	if (cmd_path == NULL)
	{
		ft_free_split(cmd);
		ft_print_error("cmd not found");
		return ;
	}
	if (execve(cmd_path, cmd, envp) == -1)
    {
		ft_free_split(cmd);
        ft_print_error("cmd exe error\n");
    }
}

void	ft_first_cmd(t_pipex *data, char **argv, char **envp)
{
	close(data->p_fd[READ]);
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd == -1)
		ft_print_error("open infile error\n");
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
		ft_print_error("infile dup2 error\n");
	close(data->infile_fd);
	if (dup2(data->p_fd[WRITE], STDOUT_FILENO) == -1)
		ft_print_error("pipe write dup2 error\n");
	close(data->p_fd[WRITE]);
	ft_exec_cmd(data, argv[2], envp);
}

void	ft_last_cmd(t_pipex *data, char **argv, char **envp)
{
	close(data->p_fd[WRITE]);
	data->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		ft_print_error("open outfile error\n");
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
		ft_print_error("outfile dup2 error\n");
	close(data->outfile_fd);
	if (dup2(data->p_fd[READ], STDIN_FILENO) == -1)
		close(data->p_fd[READ]);
	ft_exec_cmd(data, argv[3], envp);
}
