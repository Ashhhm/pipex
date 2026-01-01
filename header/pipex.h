/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:33:42 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/01 17:40:39 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <../libft/libft.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <unistd.h>

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

#endif
