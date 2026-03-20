/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:25:18 by omawele           #+#    #+#             */
/*   Updated: 2026/03/20 11:44:22 by omawele          ###   ########.fr       */
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
	size = monitor->args.size;
	has_eaten_count = monitor->args.eat_count;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (dead(monitor, i) == 2)
				return ((void *)0);
			if (has_eaten_count)
			{
				if (eat_times(monitor,  i))
					return ((void *)0);
			}		
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
	monitor->lock_last_meal = &monitor->philos[index].lock_last_meal;
	pthread_mutex_lock(monitor->lock_last_meal);
	if (absolute_now
		- monitor->philos[index].last_meal_time > monitor->args.tto_die)
	{
		pthread_mutex_unlock(monitor->lock_last_meal);
		end_simulation(monitor);
		time_since_start = absolute_now - monitor->start_time ;
		pthread_mutex_lock(monitor->print_mutex);
		printf("%ld %d died\n", time_since_start, monitor->philos[index].index);
		pthread_mutex_unlock(monitor->print_mutex);
		return (2);
	}
	else
		pthread_mutex_unlock(monitor->lock_last_meal);
	return (0);
}

int	eat_times(t_monitor *monitor, int index)
{
	unsigned int	i;
	unsigned int	full_count;

	(void)index;
	i = 0;
	full_count = 0;
	while (i < monitor->args.size)
	{
		monitor->lock_eat_count = &monitor->philos[i].lock_eat_count;
		pthread_mutex_lock(monitor->lock_eat_count);
		if (monitor->philos[i].eat_count >= monitor->args.eat_count)
			full_count++;
		pthread_mutex_unlock(monitor->lock_eat_count);
		i++;
	}
	if (full_count == monitor->args.size)
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

	size = monitor->args.size;
	i = 0;
	pthread_mutex_lock(monitor->stop_mutex);
	while (i < size)
	{
		monitor->philos[i].stop = 1;
		i++;
	}
	pthread_mutex_unlock(monitor->stop_mutex);
}
