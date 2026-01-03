/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:33:42 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/02 19:01:45 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> 

typedef struct s_pipex
{
	int	infile_fd;
	int	outfile_fd;
	int	p_fd[2];
	int	nb_argc;
	int	nb_cmd;
	int	i;
}		t_pipex;

# define WRITE 1
# define READ 0

/*error.c*/

void	ft_print_error(const char *str);
void	ft_free_split(char **split);

/*check.c*/

bool	ft_check(int argc, char **argv);
void	ft_pipex(t_pipex *data, char **argv, char **envp);

/*cmd.c*/

void	ft_last_cmd(t_pipex *data, char **argv, char **envp);
void	ft_first_cmd(t_pipex *data, char **argv, char **envp);
void	ft_exec_cmd(t_pipex *data, char *argv, char **envp);
char	*ft_cmd_path(char *cmd, char **envp);

#endif
