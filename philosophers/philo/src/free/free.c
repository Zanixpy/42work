/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:12:19 by omawele           #+#    #+#             */
/*   Updated: 2026/03/10 17:45:43 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/free.h"

void cleanup_philosophers(t_philo *philos, int size)
{
    int i;

    if (!philos)
        return;
    i = 0;
    while (i < size) 
    {
        pthread_mutex_destroy(&philos[i].lock_last_meal);
        i++;    
    }
    free(philos);
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
        free(monitor);
}

void cleanup_mutex(pthread_mutex_t **mutex)
{
    pthread_mutex_destroy(*mutex);
    free(*mutex);
}

void cleanup_all(t_fork *forks, t_philo *philos, t_monitor *monitor, int size)
{
    cleanup_mutex(&monitor->print_mutex);
    cleanup_mutex(&monitor->stop_mutex);
    cleanup_philosophers(philos, size);
    cleanup_forks(forks, size);
    cleanup_monitor(monitor);
}