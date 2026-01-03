/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:50:34 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/02 16:04:33 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

/**
 * @brief print the str error message on the STDERR and exit the program
 *
 * @param str personalize str message to be print
 */
void	ft_print_error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

/**
 * @brief free the allocated memory use by the ft_split function
 *
 * @param split char ** from ft_split function
 */
void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split);
		split = NULL;
		i++;
	}
	free(split);
}
