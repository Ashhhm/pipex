/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:50:34 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/17 10:42:16 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_print_error(const char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}

void    ft_free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split);
        split = NULL;
        i++;
    }
    free(split);
}