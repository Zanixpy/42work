/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:56:02 by omawele           #+#    #+#             */
/*   Updated: 2026/03/14 18:19:37 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validator(t_args *args, int argc, char **argv)
{
	if (argc != 5)
		return (error_args(1), 1);
	if (check_args_int(argc, argv))
	{
		return (error_args(0), 1);
	}
	args->size_phi = ft_atoi(argv[1]);
	args->tto_die = ft_atoi(argv[2]);
	args->tto_eat = ft_atoi(argv[3]);
	args->tto_sleep = ft_atoi(argv[4]);
	if (args->size_phi == 0)
		return (1);
	return (0);
}
