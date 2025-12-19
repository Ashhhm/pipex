/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:33:42 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/18 14:00:45 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

typedef struct s_pipex
{
	int		infile_fd;
	int		outfile_fd;
	int		p_fd[2];
	int		nb_argc;
	int		nb_cmd;
	int		i;
}		t_pipex;

#include <unistd.h>
#include <stdbool.h>
#include <../libft/libft.h>
#include <fcntl.h>
#include <sys/wait.h>

#define WRITE 1
#define READ 0

/*error.c*/
void    ft_print_error(const char *str);

#endif
