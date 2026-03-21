/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/03/20 15:23:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

t_monitor	*init_monitor(t_philo **philos, t_args *args,
		pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
	t_monitor	*monitor;

	monitor = malloc((sizeof(t_monitor)));
	if (!monitor)
		return (NULL);
	monitor->philos = *philos;
	monitor->args = *args;
	monitor->print_mutex = *print_mutex;
	monitor->stop_mutex = *stop_mutex;
	return (monitor);
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
		if (pthread_mutex_init(&forks[i].locker, NULL) != 0)
			return (free_forks(forks, i), NULL);
		i++;
	}
	return (forks);
}


int	init_all(t_philo **philos, t_fork **forks, t_monitor **monitor,
	t_data *data)
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*stop_mutex;


	print_mutex = create_mutex();
	if (!print_mutex)
		return (error_init(2));
	stop_mutex = create_mutex();
	if (!stop_mutex)
		return (free_mutex(&print_mutex), error_init(2));
	*forks = init_forks(data->size);
		if (!(*forks))
			return (free_mutex(&print_mutex), free_mutex(&stop_mutex), error_init(1));
	*philos = init_philosophers(data, *forks, &print_mutex, &stop_mutex);
	if (!(*philos))
		return (free_mutex(&print_mutex), free_mutex(&stop_mutex),
			free_mutex(&forks_mutex), free_forks(*forks, data->size),
			error_init(2));
	if ((*philos)->data.size == 1)
		return (0);
	*monitor = init_monitor(philos, data, &print_mutex, &stop_mutex);
	if (!(*monitor))
		return (clean(*forks, *philos, *monitor, data->size),
			error_init(3));
	return (0);
}
