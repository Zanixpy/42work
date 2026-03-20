/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:35:19 by omawele           #+#    #+#             */
/*   Updated: 2026/03/20 11:31:23 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	precise_sleep(t_philo *philo, long duration_ms)
{
	long	start;
	long	now;

	start = get_time_in_milliseconds();
	if (start == -1)
		return ;
	while (!should_stop(philo))
	{
		now = get_time_in_milliseconds();
		if (now == -1 || now - start >= duration_ms)
			break ;
		usleep(200);
	}
}

int	take_forks(t_philo *philo)
{
	long	current_time;

	while (!should_stop(philo))
	{
		pthread_mutex_lock(philo->forks_mutex);
		if (!philo->left_fork->in_use && !philo->right_fork->in_use)
		{
			philo->left_fork->in_use = 1;
			philo->right_fork->in_use = 1;
			pthread_mutex_unlock(philo->forks_mutex);
			if (should_stop(philo))
				return (release_forks(philo), 1);
			current_time = get_time_in_milliseconds() - philo->start_time;
			pthread_mutex_lock(philo->print_mutex);
			printf("%ld %d has taken a fork\n", current_time, philo->index);
			pthread_mutex_unlock(philo->print_mutex);
			if (should_stop(philo))
				return (release_forks(philo), 1);
			current_time = get_time_in_milliseconds() - philo->start_time;
			pthread_mutex_lock(philo->print_mutex);
			printf("%ld %d has taken a fork\n", current_time, philo->index);
			pthread_mutex_unlock(philo->print_mutex);
			return (0);
		}
		pthread_mutex_unlock(philo->forks_mutex);
		usleep(200);
	}
	return (1);
}

int	should_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(philo->stop_mutex);
	stop = philo->stop;
	pthread_mutex_unlock(philo->stop_mutex);
	return (stop);
}

void release_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->forks_mutex);
	philo->right_fork->in_use = 0;
	philo->left_fork->in_use = 0;
	pthread_mutex_unlock(philo->forks_mutex);
}

void release_one_fork(t_philo *philo)
{
	release_forks(philo);
}
