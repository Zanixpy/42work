/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:48:06 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 17:07:37 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error.h"

int error_args(int code)
{
    if (code)
	    ft_putstr_fd("format: [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]\n", 2);
    else
	    ft_putstr_fd("args: all values must be positive integer\n", 2);
    return (ERRARGS);
}

int error_init(int code)
{
    if (code)
        ft_putstr_fd("malloc: error occured in the forks initialization\n", 2);
    else
        ft_putstr_fd("malloc: error occured in the philos initialization\n", 2);
    return (ERRINIT);
}