/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:56:02 by omawele           #+#    #+#             */
/*   Updated: 2026/02/16 18:37:47 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}


int args_checker(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putstr_fd("format: [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]\n", 2);
		return (EXIT_FAILURE);
	}
    if (check_args_int(argc, argv))
	{
		ft_putstr_fd("args: all values must be positive integer\n", 2);
        return (EXIT_FAILURE);
	}
    return (EXIT_SUCCESS); 
}
