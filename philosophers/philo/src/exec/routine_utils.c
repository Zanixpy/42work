/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:35:19 by omawele           #+#    #+#             */
/*   Updated: 2026/04/06 22:11:49 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	precise_sleep(t_philo *philo, long duration_ms)
{
	long	start;
	long	now;

	start = get_time_ms();
	while (!should_stop(philo))
	{
		now = get_time_ms();
		if (now - start >= duration_ms)
			break ;
		usleep(3);
	}
}

int	take_forks(t_philo *philo)
{
	if (should_stop(philo))
		return (1);
	if (philo->index % 2 == 0)
		pthread_mutex_lock(&philo->right_fork->locker);
	else
		pthread_mutex_lock(&philo->left_fork->locker);
	if (should_stop(philo))
		return (release_one_fork(philo), 1);
	pthread_mutex_lock(philo->mutexes.print_mutex);
	printf("%ld %d has taken a fork\n", get_time_ms() - philo->data.start_time,
		philo->index);
	pthread_mutex_unlock(philo->mutexes.print_mutex);
	if (philo->index % 2 == 0)
		pthread_mutex_lock(&philo->left_fork->locker);
	else
		pthread_mutex_lock(&philo->right_fork->locker);
	if (should_stop(philo))
		return (release_forks(philo), 1);
	pthread_mutex_lock(philo->mutexes.print_mutex);
	printf("%ld %d has taken a fork\n", get_time_ms() - philo->data.start_time,
		philo->index);
	pthread_mutex_unlock(philo->mutexes.print_mutex);
	return (0);
}

int	should_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(philo->mutexes.stop_mutex);
	stop = philo->stop;
	pthread_mutex_unlock(philo->mutexes.stop_mutex);
	return (stop);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->right_fork->locker);
	pthread_mutex_unlock(&philo->left_fork->locker);
}

void	release_one_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
		pthread_mutex_unlock(&philo->right_fork->locker);
	else
		pthread_mutex_unlock(&philo->left_fork->locker);
}
