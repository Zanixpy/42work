/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/02/16 21:08:49 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_args args;
    
    if (args_checker(argc, argv))
        return (EXIT_FAILURE);
    convert_args_in_int(&args, argv);
    
        
    
    
    return (EXIT_SUCCESS);
}
