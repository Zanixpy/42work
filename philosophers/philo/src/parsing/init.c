/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/03/14 18:57:23 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

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

static init_monitor(t_philo **philos, t_args *args, pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
    t_monitor *monitor;

    monitor = malloc((sizeof(t_monitor)));
    if (!monitor)
        return (NULL);
    monitor->philos = *philos;
	monitor->args = *args;
	monitor->print_mutex = print_mutex;
	monitor->stop_mutex = stop_mutex;
    return (monitor);
}

int	init_all(t_philo **philos, t_fork **forks, t_monitor **monitor,
		t_args *args)
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*stop_mutex;

	*forks = init_forks(args->size_phi);
	if (!(*forks))
		return (error_init(1));
	print_mutex = create_mutex();
	if (!print_mutex)
		return (free_forks(*forks, args->size_phi), error_init(2));
	stop_mutex = create_mutex();
	if (!stop_mutex)
		return (free_mutex(&print_mutex), free_forks(*forks, args->size_phi),
			error_init(2));
	*philos = init_philosophers(args, *forks, print_mutex, stop_mutex);
	if (!(*philos))
		return (clean(*forks, *philos, *monitor, args->size_phi),
			error_init(2));
	*monitor = malloc((sizeof(t_monitor)));
	if (!(*monitor))
		return (clean(*forks, *philos, *monitor, args->size_phi),
			error_init(3));
	return (0);
}
