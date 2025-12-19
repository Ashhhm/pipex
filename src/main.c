/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:35:37 by hammeah           #+#    #+#             */
/*   Updated: 2025/12/18 13:52:56 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex data;
      
    if (argc >= 5 && ft_check_arg(argc, argv) == true)
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
