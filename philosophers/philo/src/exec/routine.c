/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/03/20 12:47:00 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	*routine_philosophers(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->index % 2 == 0)
		usleep(100);
	if (philo->args.size % 2 != 0)
	{
		if (philo->index == philo->args.size)
			precise_sleep(philo, philo->args.tto_eat);
	}
	while (1)
	{
		if (should_stop(philo))
			break;
		eat(philo);
		psleep(philo);
		think(philo);
	}
	return ((void *)0);
}

void	*routine_philosopher(void *args)
{
	t_philo	*philo;
	long	current_time;

	philo = (t_philo *)args;
	current_time = get_time_in_milliseconds() - philo->start_time;
	pthread_mutex_lock(&philo->right_fork->locker);
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d has taken a fork\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->right_fork->locker);
	precise_sleep(philo, philo->args.tto_die);
	current_time = get_time_in_milliseconds() - philo->start_time;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d died\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
	return ((void *)0);
}
