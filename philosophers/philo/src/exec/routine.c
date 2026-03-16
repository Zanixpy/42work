/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/03/16 16:49:19 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void print_fork(t_philo *philo)
{
    long	current_time;

	current_time = get_time_in_milliseconds();
	if (current_time == -1)
		return ;
	current_time -= philo->start_time;
	if (should_stop(philo))
		return ;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d has taken a fork\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
}

void print_eating(t_philo *philo)
{
    long	current_time;

	current_time = get_time_in_milliseconds();
	if (current_time == -1)
		return ;
	current_time -= philo->start_time;
	if (should_stop(philo))
		return ;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d is eating\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
}

void	*routine_philosophers(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!should_stop(philo))
	{
		eat(philo);
		psleep(philo);
		think(philo);
	}
	return ((void *)0);
}

void	*routine_philosopher(void *args)
{
	t_philo	*philo;
	int		check_eat;
	int		check_think;

	check_eat = 0;
	check_think = 0;
	philo = (t_philo *)args;
	while (!should_stop(philo))
	{
		eat_one(philo, &check_eat);
		think_one(philo, &check_think);
	}
	return ((void *)0);
}
