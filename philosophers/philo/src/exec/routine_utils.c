/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:35:19 by omawele           #+#    #+#             */
/*   Updated: 2026/03/16 16:25:38 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"


void take_first_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
		pthread_mutex_lock(&philo->left_fork.locker);
	else
		pthread_mutex_lock(&philo->right_fork.locker);
}

void take_second_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
		pthread_mutex_lock(&philo->right_fork.locker);
	else
		pthread_mutex_lock(&philo->left_fork.locker);
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
    pthread_mutex_unlock(&philo->right_fork.locker);
	pthread_mutex_unlock(&philo->left_fork.locker);  
}

void release_one_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
		pthread_mutex_unlock(&philo->left_fork.locker);
	else
		pthread_mutex_unlock(&philo->right_fork.locker);
}

