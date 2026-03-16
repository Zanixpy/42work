/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:12:50 by omawele           #+#    #+#             */
/*   Updated: 2026/03/16 16:42:45 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void	psleep(t_philo *philo)
{
	long	current_time;

	current_time = get_time_in_milliseconds();
	if (current_time == -1)
		return ;
	current_time -= philo->start_time;
	if (should_stop(philo))
		return ;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d is sleeping\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
	usleep(philo->args.tto_sleep * 1000);
}

void	eat(t_philo *philo)
{
	long	current_time;

	current_time = get_time_in_milliseconds();
	if (current_time == -1)
		return ;
	current_time -= philo->start_time;
	take_first_fork(philo);
	if (should_stop(philo))
		return (release_one_fork(philo));
	print_fork(philo);
	take_second_fork(philo);
	if (should_stop(philo))
		return (release_forks(philo));
	print_fork(philo);
	pthread_mutex_lock(&philo->lock_last_meal);
	philo->last_meal_time = get_time_in_milliseconds();
	pthread_mutex_unlock(&philo->lock_last_meal);
	if (should_stop(philo))
		return (release_forks(philo));
	print_eating(philo);
	usleep(philo->args.tto_eat * 1000);
	release_forks(philo);
}

void	think(t_philo *philo)
{
	long	current_time;

	current_time = get_time_in_milliseconds();
	if (current_time == -1)
		return ;
	current_time -= philo->start_time;
	if (should_stop(philo))
		return ;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d is thinking\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
}

void	eat_one(t_philo *philo, int *check_eat)
{
	long	current_time;

	if (*check_eat)
		return ;
	if (should_stop(philo))
		return ;
	current_time = get_time_in_milliseconds();
	if (current_time == -1)
		return ;
	current_time -= philo->start_time;
	*check_eat = 1;
	pthread_mutex_lock(&philo->right_fork.locker);
	if (should_stop(philo))
	{
		pthread_mutex_unlock(&philo->right_fork.locker);
		return ;
	}
	print_fork(philo);
	pthread_mutex_unlock(&philo->right_fork.locker);
}

void	think_one(t_philo *philo, int *check_think)
{
	long	current_time;

	if (*check_think)
		return ;
	if (should_stop(philo))
		return ;
	current_time = get_time_in_milliseconds();
	if (current_time == -1)
		return ;
	current_time -= philo->start_time;
	*check_think = 1;
	pthread_mutex_lock(philo->print_mutex);
	printf("%ld %d is thinking\n", current_time, philo->index);
	pthread_mutex_unlock(philo->print_mutex);
}
