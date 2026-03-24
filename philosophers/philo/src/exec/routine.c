/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/03/22 22:05:22 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	*routine_philosophers(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->index % 2 == 0)
		usleep(100);
	if (philo->data.size % 2 != 0)
	{
		if (philo->index == philo->data.size)
			precise_sleep(philo, philo->data.tto_eat);
	}
	while (1)
	{
		if (should_stop(philo))
			break ;
		eat(philo);
		psleep(philo);
		think(philo);
	}
	return ((void *)0);
}

void	*routine_philosopher(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->left_fork->locker);
	pthread_mutex_lock(philo->mutexes.print_mutex);
	printf("%ld %d has taken a fork\n", get_time_ms() - philo->data.start_time,
		philo->index);
	pthread_mutex_unlock(philo->mutexes.print_mutex);
	pthread_mutex_unlock(&philo->left_fork->locker);
	precise_sleep(philo, philo->data.tto_die);
	pthread_mutex_lock(philo->mutexes.print_mutex);
	printf("%ld %d died\n", get_time_ms() - philo->data.start_time,
		philo->index);
	pthread_mutex_unlock(philo->mutexes.print_mutex);
	return ((void *)0);
}
