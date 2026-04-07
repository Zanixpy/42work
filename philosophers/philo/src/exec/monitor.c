/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:25:18 by omawele           #+#    #+#             */
/*   Updated: 2026/04/07 16:52:44 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	*routine_monitor(void *args)
{
	t_monitor	*monitor;
	int			i;
	int			size;

	monitor = (t_monitor *)args;
	size = monitor->data.size;
	while (1)
	{
		i = 0;
		while (i < size)
		{
			if (is_dead(monitor, i))
				return ((void *)0);
			if (check_eat_times(monitor, monitor->data.eat_count))
				return ((void *)0);
			i++;			
		}
		usleep(5);
	}
	return ((void *)0);
}

int	is_dead(t_monitor *monitor, int index)
{
	size_t now;
	
	monitor->lock_last_meal = &monitor->philos[index].lock_last_meal;
	pthread_mutex_lock(monitor->lock_last_meal);
	now = get_time();
	if (now - monitor->philos[index].last_meal_time >= monitor->data.tto_die)
	{
		pthread_mutex_unlock(monitor->lock_last_meal);
		print_death(monitor, monitor->philos[index].index);
		pthread_mutex_lock(monitor->stop_mutex);
		*(monitor->stop) = 1;
		pthread_mutex_unlock(monitor->stop_mutex);
		return (1);					
	}
	else
		pthread_mutex_unlock(monitor->lock_last_meal);
	return (0);					
}

int	check_eat_times(t_monitor *monitor, int is_count)
{
	unsigned int	i;
	unsigned int	full_count;

	if (!is_count)
		return (0);
	i = 0;
	full_count = 0;
	while (i < monitor->data.size)
	{
		monitor->lock_eat_count = &monitor->philos[i].lock_eat_count;
		pthread_mutex_lock(monitor->lock_eat_count);
		if (monitor->philos[i].eat_count >= monitor->data.eat_count)
			full_count++;
		pthread_mutex_unlock(monitor->lock_eat_count);
		i++;
	}
	if (full_count == monitor->data.size)
	{
		pthread_mutex_lock(monitor->stop_mutex);
		*(monitor->stop) = 1;
		pthread_mutex_unlock(monitor->stop_mutex);	
	}
	return (0);
}

void print_death(t_monitor *monitor, int index)
{
	pthread_mutex_lock(monitor->print_mutex);
	printf("%ld %d died\n", get_time_ms(monitor->data.start_time), index);
	pthread_mutex_unlock(monitor->print_mutex);	
}