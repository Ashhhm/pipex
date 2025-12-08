/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:33:42 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/08 19:45:43 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_pipex
{
	int	pip;
	int	fdp[2];
}		t_pipex;

#include <unistd.h>
#include <stdbool.h>
#include <libft.h>