/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:12:50 by omawele           #+#    #+#             */
/*   Updated: 2026/03/20 11:55:17 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	psleep(t_philo *philo)
{
	long	current_time;

	current_time = get_time_in_milliseconds() - philo->start_time;
	if (should_stop(philo))
		return ;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d is sleeping\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
	precise_sleep(philo, philo->args.tto_sleep);
}

void	eat(t_philo *philo)
{
	long	current_time;

	if (should_stop(philo))
		return ;
	if (take_forks(philo))
		return;
	if (should_stop(philo))
		return (release_forks(philo));
	current_time = get_time_in_milliseconds() - philo->start_time;
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(&philo->lock_last_meal);
	philo->last_meal_time = get_time_in_milliseconds();
	pthread_mutex_unlock(&philo->lock_last_meal);
	printf("%ld %d is eating\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
	precise_sleep(philo, philo->args.tto_eat);
	release_forks(philo); 
	pthread_mutex_lock(&philo->lock_eat_count);
	philo->eat_count += 1;
	pthread_mutex_unlock(&philo->lock_eat_count);
}

void	think(t_philo *philo)
{
	long	current_time;

	if (should_stop(philo))
		return ;
	current_time = get_time_in_milliseconds() - philo->start_time;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d is thinking\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
}
