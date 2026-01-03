/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:39:24 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/02 18:57:49 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"
#include "../libft/libft.h"

void	ft_pipex(t_pipex *data, char **argv, char **envp)
{
	pid_t	f_value;
	int		status;

	if (pipe(data->p_fd) == -1)
		ft_print_error("pipe error\n");
	f_value = fork();
	if (f_value < 0)
		ft_print_error("fork error\n");
	else if (f_value == 0)
		ft_first_cmd(data, argv, envp);
	else
	{
		waitpid(f_value, &status, 0);
		ft_last_cmd(data, argv, envp);
	}
}

/**
 * @brief checking if the arg are not empty cmd
 *
 * @param argc nb of arg
 * @param argv arg content
 * @return true : arg are not empty
 * @return false : at least one arg is empty
 */
bool	ft_check(int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc - 1)
	{
		if (argv[i][0] == '\0')
			return (false);
		i++;
	}
	return (true);
}
