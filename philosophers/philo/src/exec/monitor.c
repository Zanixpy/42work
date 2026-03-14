/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:25:18 by omawele           #+#    #+#             */
/*   Updated: 2026/03/14 18:19:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
#include <string.h>

void	*routine_monitor(void *args)
{
	t_monitor	*monitor;
	int			i;
	int			size;

	monitor = (t_monitor *)args;
	size = monitor->args.size_phi;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (dead(monitor, i) == 2)
				return ((void *)0);
			i++;
		}
		usleep(1000);
	}
	return ((void *)0);
}

int	dead(t_monitor *monitor, int index)
{
	long	absolute_now;
	long	time_since_start;

	absolute_now = get_time_in_milliseconds();
	if (absolute_now == -1)
		return (1);
	monitor->lock_last_meal = &monitor->philos[index].lock_last_meal;
	pthread_mutex_lock(monitor->lock_last_meal);
	if (absolute_now
		- monitor->philos[index].last_meal_time >= monitor->args.tto_die)
	{
		pthread_mutex_unlock(monitor->lock_last_meal);
		end_simulation(monitor);
		time_since_start = absolute_now - monitor->start_time;
		pthread_mutex_lock(monitor->print_mutex);
		printf("%ld %d died\n", time_since_start, monitor->philos[index].index);
		pthread_mutex_unlock(monitor->print_mutex);
		return (2);
	}
	else
		pthread_mutex_unlock(monitor->lock_last_meal);
	return (0);
}

void	end_simulation(t_monitor *monitor)
{
	int	size;
	int	i;

	size = monitor->args.size_phi;
	i = 0;
	pthread_mutex_lock(monitor->stop_mutex);
	while (i < size)
	{
		monitor->philos[i].stop = 1;
		i++;
	}
	pthread_mutex_unlock(monitor->stop_mutex);
}
