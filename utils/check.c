/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:39:24 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/08 19:41:45 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool    ft_check(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc != 5)
        return (false);
    while (argv[i])
    {
        if (argv[i][0] == '\0')
            return (false);
        i++;
    }
    return (true);
}