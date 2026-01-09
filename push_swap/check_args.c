/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:05:32 by omawele           #+#    #+#             */
/*   Updated: 2026/01/08 15:28:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (argv[i][0] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_int_limit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-')
			j = 0;
		if (strcmp_int_limit(argv[i], j))
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (check_args_int(argc, argv))
		return (2);
	if (check_int_limit(argc, argv))
		return (3);
	if (check_duplicates(argc, argv))
		return (4);
	return (0);
}
