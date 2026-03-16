/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/03/16 16:06:11 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

t_monitor *init_monitor(t_philo **philos, t_args *args, pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
    t_monitor *monitor;

    monitor = malloc((sizeof(t_monitor)));
    if (!monitor)
        return (NULL);
    monitor->philos = *philos;
	monitor->args = *args;
	monitor->print_mutex = *print_mutex;
	monitor->stop_mutex = *stop_mutex;
    return (monitor);
}

t_philo *init_philosophers(t_args *args, t_fork *forks, pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
    t_philo *philos;

    if (args->size == 1)
        philos = malloc_one_philosopher(args, forks, print_mutex, stop_mutex);
    else
        philos = malloc_philosophers(args, forks, print_mutex, stop_mutex);
    if (!philos)
        return (NULL);
    return (philos);
}

t_philo	*malloc_philosophers(t_args *args, t_fork *forks,
		pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
	t_philo			*philos;
	unsigned int	i;

	philos = malloc(args->size * sizeof(t_philo));
	if (!philos)
		return (NULL);
	i = -1;
	while (++i < args->size)
	{
		philos[i].index = i;
		philos[i].last_meal_time = 0;
		philos[i].args = *args;
		philos[i].print_mutex = *print_mutex;
		philos[i].stop_mutex = *stop_mutex;
		philos[i].stop = 0;
		if (pthread_mutex_init(&philos[i].lock_last_meal, NULL) != 0)
			return (free_philos(philos, i), NULL);
		if (i == 0)
			philos[i].right_fork = forks[args->size - 1];
		else
			philos[i].right_fork = forks[i - 1];
		philos[i].left_fork = forks[i];
	}
	return (philos);
}

t_philo	*malloc_one_philosopher(t_args *args, t_fork *forks,
		pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo[0].index = 0;
	philo[0].last_meal_time = 0;
	philo[0].args = *args;
	philo[0].print_mutex = *print_mutex;
	philo[0].stop_mutex = *stop_mutex;
	philo[0].right_fork = forks[0];
	philo[0].stop = 0;
	if (pthread_mutex_init(&philo[0].lock_last_meal, NULL) != 0)
		return (free_philos(philo, 1), NULL);
	return (philo);
}

t_fork	*init_forks(int nb_forks)
{
	t_fork	*forks;
	int		i;

	forks = malloc(nb_forks * sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_forks)
	{
		forks[i].index = i;
		if (pthread_mutex_init(&forks[i].locker, NULL) != 0)
			return (free_forks(forks, i), NULL);
		i++;
	}
	return (forks);
}


