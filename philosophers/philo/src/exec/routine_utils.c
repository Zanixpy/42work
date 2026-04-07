/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:35:19 by omawele           #+#    #+#             */
/*   Updated: 2026/04/07 16:44:43 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	precise_sleep(size_t start_time, size_t duration_ms)
{
	while (1)
	{
		if (get_time() - start_time >= duration_ms)
			break ;
		usleep(3);
	}
}

void	release_forks(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(&philo->left_fork->locker);
		pthread_mutex_unlock(&philo->right_fork->locker);
	}
	else
	{
		pthread_mutex_unlock(&philo->right_fork->locker);
		pthread_mutex_unlock(&philo->left_fork->locker);
	}
}

void print_state(t_philo *philo, int index, char *text)
{
	pthread_mutex_lock(philo->print_mutex);
	pthread_mutex_lock(philo->stop_mutex);
	if (!philo->stop)
		printf("%ld %d %s\n", get_time_ms(philo->data.start_time), index, text);
	pthread_mutex_unlock(philo->stop_mutex);
	pthread_mutex_unlock(philo->print_mutex);
}
