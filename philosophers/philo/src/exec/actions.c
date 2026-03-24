/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:12:50 by omawele           #+#    #+#             */
/*   Updated: 2026/03/24 00:33:25 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	psleep(t_philo *philo)
{
	if (should_stop(philo))
		return ;
	pthread_mutex_lock(philo->mutexes.print_mutex);
	printf("%ld %d is sleeping\n", get_time_ms() - philo->data.start_time,
		philo->index);
	pthread_mutex_unlock(philo->mutexes.print_mutex);
	precise_sleep(philo, philo->data.tto_sleep);
}

void	eat(t_philo *philo)
{
	if (take_forks(philo))
		return ;
	pthread_mutex_lock(philo->mutexes.print_mutex);
	pthread_mutex_lock(&philo->mutexes.lock_last_meal);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->mutexes.lock_last_meal);
	printf("%ld %d is eating\n", get_time_ms() - philo->data.start_time,
		philo->index);
	pthread_mutex_unlock(philo->mutexes.print_mutex);
	precise_sleep(philo, philo->data.tto_eat);
	release_forks(philo);
	pthread_mutex_lock(&philo->mutexes.lock_eat_count);
	philo->eat_count += 1;
	pthread_mutex_unlock(&philo->mutexes.lock_eat_count);
}

void	think(t_philo *philo)
{
	if (should_stop(philo))
		return ;
	pthread_mutex_lock(philo->mutexes.print_mutex);
	printf("%ld %d is thinking\n", get_time_ms() - philo->data.start_time,
		philo->index);
	pthread_mutex_unlock(philo->mutexes.print_mutex);
	precise_sleep(philo, 2);
}
