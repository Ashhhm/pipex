/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:35:37 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/02 16:07:09 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;

	if (argc >= 5 && ft_check(argc, argv) == true)
	{
		data.nb_argc = argc;
		data.nb_cmd = argc - 3;
		ft_pipex(&data, argv, envp);
	}
	else
	{
		ft_print_error("");
	}
	return (0);
}
