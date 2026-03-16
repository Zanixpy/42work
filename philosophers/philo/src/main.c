/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/03/16 16:53:08 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_threads(t_philo **philos, t_monitor **monitor, int size)
{
	int		i;
	long	start_time;

	i = -1;
	start_time = get_time_in_milliseconds();
	if (start_time == -1)
		return (1);
	(*monitor)->start_time = start_time;
	while (++i < size)
	{
		(*philos)[i].start_time = start_time;
		(*philos)[i].last_meal_time = start_time;
		if (pthread_create(&(*philos)[i].tid, NULL, &routine_philosophers,
				(void *)&(*philos)[i]) != 0)
			return (1);
	}
	if (pthread_create(&(*monitor)->tid, NULL, &routine_monitor,
			(void *)(*monitor)) != 0)
		return (1);
	if (pthread_join((*monitor)->tid, NULL) != 0)
		return (1);
	i = -1;
    while (++i < size)
	{
        if (pthread_join((*philos)[i].tid, NULL) != 0)
			return (1);
	}
	return (0);
}

int	create_thread_one_philosopher(t_philo **philos, t_monitor **monitor)
{
	long	start_time;

	start_time = get_time_in_milliseconds();
	if (start_time == -1)
		return (1);
	(*philos)[0].start_time = start_time;
	(*philos)[0].last_meal_time = start_time;
	(*monitor)->start_time = start_time;
	if (pthread_create(&(*philos)[0].tid, NULL, &routine_philosopher,
			(void *)&(*philos)[0]) != 0)
		return (1);
    if (pthread_join((*philos)[0].tid, NULL) != 0)
		return (1);
	if (pthread_create(&(*monitor)->tid, NULL, &routine_monitor,
			(void *)(*monitor)) != 0)
		return (1);
    if (pthread_join((*monitor)->tid, NULL) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_args		args;
	t_fork		*forks;
	t_philo		*philos;
	t_monitor	*monitor;

	if (validator(&args, argc, argv))
		return (ERRARGS);
	forks = NULL;
	philos = NULL;
	monitor = NULL;
	if (init_all(&philos, &forks, &monitor, &args))
		return (ERRINIT);
	if (args.size == 1)
	{
		if (create_thread_one_philosopher(&philos, &monitor))
			return (clean(forks, philos, monitor, args.size),
				ERRTHREAD);
	}
	else
	{
		if (create_threads(&philos, &monitor, args.size))
			return (clean(forks, philos, monitor, args.size),
				ERRTHREAD);
	}
	return (clean(forks, philos, monitor, args.size), EXIT_SUCCESS);
}
