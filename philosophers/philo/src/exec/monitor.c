/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:25:18 by omawele           #+#    #+#             */
/*   Updated: 2026/03/24 00:34:49 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	*routine_monitor(void *args)
{
	t_monitor	*monitor;
	int			i;
	int			size;
	int			has_eaten_count;

	monitor = (t_monitor *)args;
	size = monitor->data.size;
	has_eaten_count = monitor->data.eat_count;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (dead(monitor, i) == 2)
				return ((void *)0);
			if (has_eaten_count)
			{
				if (check_eat_times(monitor))
					return ((void *)0);
			}
			i++;
		}
		usleep(10);
	}
	return ((void *)0);
}

int	dead(t_monitor *monitor, int index)
{
	long	absolute_now;

	monitor->lock_last_meal = &monitor->philos[index].mutexes.lock_last_meal;
	pthread_mutex_lock(monitor->lock_last_meal);
	absolute_now = get_time_ms();
	if (absolute_now
		- monitor->philos[index].last_meal_time > monitor->data.tto_die)
	{
		pthread_mutex_unlock(monitor->lock_last_meal);
		end_simulation(monitor);
		pthread_mutex_lock(monitor->mutexes.print_mutex);
		printf("%ld %d died\n", absolute_now - monitor->data.start_time,
			monitor->philos[index].index);
		pthread_mutex_unlock(monitor->mutexes.print_mutex);
		return (2);
	}
	else
		pthread_mutex_unlock(monitor->lock_last_meal);
	return (0);
}

int	check_eat_times(t_monitor *monitor)
{
	unsigned int	i;
	unsigned int	full_count;

	i = 0;
	full_count = 0;
	while (i < monitor->data.size)
	{
		monitor->lock_eat_count = &monitor->philos[i].mutexes.lock_eat_count;
		pthread_mutex_lock(monitor->lock_eat_count);
		if (monitor->philos[i].eat_count >= monitor->data.eat_count)
			full_count++;
		pthread_mutex_unlock(monitor->lock_eat_count);
		i++;
	}
	if (full_count == monitor->data.size)
	{
		end_simulation(monitor);
		return (1);
	}
	return (0);
}

void	end_simulation(t_monitor *monitor)
{
	int	size;
	int	i;

	size = monitor->data.size;
	i = 0;
	pthread_mutex_lock(monitor->mutexes.stop_mutex);
	while (i < size)
	{
		monitor->philos[i].stop = 1;
		i++;
	}
	pthread_mutex_unlock(monitor->mutexes.stop_mutex);
}
