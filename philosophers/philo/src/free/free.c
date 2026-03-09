/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:12:19 by omawele           #+#    #+#             */
/*   Updated: 2026/03/09 15:14:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/free.h"

void cleanup_philosophers(t_philo *philos)
{
    if (philos)
    {
        pthread_mutex_destroy(philos->print_mutex);
        free(philos->print_mutex);
        free(philos);   
    }
}

void cleanup_forks(t_fork *forks, int size)
{
    int i;

    if (!forks)
        return;
    i = 0;
    while (i < size) 
    {
        pthread_mutex_destroy(&forks[i].locker);
        i++;
    }
    free(forks);
}

void cleanup_monitor(t_monitor *monitor)
{
    if (monitor)
    {
        pthread_mutex_destroy(monitor->lock_last_meal);
        free(monitor->lock_last_meal);
        free(monitor);
    }
}

void cleanup_all(t_fork *forks, t_philo *philos, t_monitor *monitor, int size)
{
    cleanup_philosophers(philos);
    cleanup_forks(forks, size);
    cleanup_monitor(monitor);
}