/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:54:51 by omawele           #+#    #+#             */
/*   Updated: 2026/03/18 16:51:11 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

int	strcmp_int_limit(char *s)
{
	char	*int_max;
	int		size;

    int_max = "2147483647";
	size = ft_strlen(s);
	if (size <= 9)
		return (0);
	while (*int_max)
	{
		if (*int_max < *s)
			return (1);
		int_max++;
		s++;
	}
	return (0);
}

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
        if (strcmp_int_limit(argv[i]))
            return (1);
		i++;
	}
	return (0);
}

int	validator(t_args *args, int argc, char **argv)
{
    struct timeval tv;
	
    if (gettimeofday(&tv, NULL) == -1)
		return (1);
	if (argc != 5 && argc != 6)
		return (error_args(1), 1);
	if (check_args_int(argc, argv))
	{
		return (error_args(0), 1);
	}
	args->size = ft_atoi(argv[1]);
	args->tto_die = ft_atoi(argv[2]);
	args->tto_eat = ft_atoi(argv[3]);
	args->tto_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        args->eat_count = ft_atoi(argv[5]);
    else 
    {
        args->eat_count = 0;    
    }
	if (args->size <= 0)
		return (1);
	return (0);
}

static pthread_mutex_t	*create_mutex(void)
{
	pthread_mutex_t	*mutex;

	mutex = malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (NULL);
	if (pthread_mutex_init(mutex, NULL) != 0)
		return (free(mutex), NULL);
	return (mutex);
}

int	init_all(t_philo **philos, t_fork **forks, t_monitor **monitor,
	t_args *args)
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*stop_mutex;
	pthread_mutex_t	*forks_mutex;

	*forks = init_forks(args->size);
	if (!(*forks))
		return (error_init(1));
	print_mutex = create_mutex();
	if (!print_mutex)
		return (free_forks(*forks, args->size), error_init(2));
	stop_mutex = create_mutex();
	if (!stop_mutex)
		return (free_mutex(&print_mutex), free_forks(*forks, args->size),
			error_init(2));
	forks_mutex = create_mutex();
	if (!forks_mutex)
		return (free_mutex(&print_mutex), free_mutex(&stop_mutex),
			free_forks(*forks, args->size), error_init(2));
	*philos = init_philosophers(args, *forks, &print_mutex, &stop_mutex,
			&forks_mutex);
	if (!(*philos))
		return (free_mutex(&print_mutex), free_mutex(&stop_mutex),
			free_mutex(&forks_mutex), free_forks(*forks, args->size),
			error_init(2));
	if ((*philos)->args.size == 1)
		return (0);
	*monitor = init_monitor(philos, args, &print_mutex, &stop_mutex);
	if (!(*monitor))
		return (clean(*forks, *philos, *monitor, args->size),
			error_init(3));
	return (0);
}
