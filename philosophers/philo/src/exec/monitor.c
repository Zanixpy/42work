/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:25:18 by omawele           #+#    #+#             */
/*   Updated: 2026/03/09 16:24:14 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
#include <string.h>

int create_monitor(t_monitor **monitor)
{
    if (pthread_create(&(*monitor)->tid, NULL, &routine_monitor, (void *)(*monitor)) != 0)
        return (1);
    if (pthread_join((*monitor)->tid, NULL) != 0)
        return (1);
    return (0);
}

void *routine_monitor(void *args)
{
    t_monitor *monitor;
    int i;
    int size;
    long current_time;

    monitor = (t_monitor *)args;
    size = monitor->args.nb_philos_forks;
    i = 0;
    while (i < size && !monitor->philos[0]->stop) 
    {
        current_time = get_time_in_milliseconds();
        if (current_time == -1)
            return ((void *)1);
        current_time -= monitor->start_time;
        // pthread_mutex_lock(monitor->lock_last_meal);
        if (current_time - monitor->philos[i]->last_meal_time >= monitor->args.tto_die)
        {
            pthread_mutex_lock(monitor->print_mutex);
            printf("Here\n");
            printf("%ld %d died\n", current_time, monitor->philos[i]->index);
            pthread_mutex_unlock(monitor->print_mutex);
            end_simulation(monitor);
        }    
        // pthread_mutex_unlock(monitor->lock_last_meal);
        i++;
        if (i == size)
            i = 0;
    }
    return ((void *)0);
}

// int dead(t_philo *philo)
// {
//     long current_time;

//     current_time = get_time_in_milliseconds();
//     if (current_time == -1)
//         return (1);
//     current_time -= philo->start_time;
//     if (current_time - philo->last_meal_time >= philo->args.tto_die)
//     {
//         pthread_mutex_lock(philo->print_mutex);
//         printf("%ld %d died\n", current_time, philo->index);
//         pthread_mutex_unlock(philo->print_mutex); 
//         return (1);
//     }
//     return (0);
// }

void end_simulation(t_monitor *monitor)
{
    int size;
    int i;

    size = monitor->args.nb_philos_forks;
    i = 0;
    while (i < size) 
    {
        monitor->philos[i]->stop = 1;
        i++; 
    }   
}
