/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/03/09 16:19:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <string.h>

int create_threads(t_philo **philos, t_monitor **monitor, int size)
{
    int i;
    long start_time;

    i = -1;
    start_time = get_time_in_milliseconds();
    if (start_time == -1)
        return (1);
    while (++i < size) 
    {
        (*philos)[i].start_time = start_time;
        (*philos)[i].lock_last_meal = (*monitor)->lock_last_meal;
        if (pthread_create(&(*philos)[i].tid, NULL, &routine_philosopher, (void *)&(*philos)[i]) != 0)
            return (1);
    }
    (*monitor)->start_time = start_time;
    if (create_monitor(monitor))
        return (1);
    i = -1;
    while (++i < size) 
    {
        if (pthread_join((*philos)[i].tid, NULL) != 0)
            return (1);
    }
    return (0); 
}

int create_thread_one_philosopher(t_philo **philos, t_monitor **monitor)
{
    long start_time;

    start_time = get_time_in_milliseconds();
    if (start_time == -1)
        return (1);
    (*philos)[0].start_time = start_time;
    if (pthread_create(&(*philos)[0].tid, NULL, &routine_only_one_philosopher, (void *)&(*philos)[0]) != 0)
        return (1);
    if (pthread_create(&(*monitor)->tid, NULL, &routine_monitor, (void *)(*monitor)) != 0)
        return (1);
    if (pthread_join((*monitor)->tid, NULL) != 0)
        return (1);
    if (pthread_join((*philos)[0].tid, NULL) != 0)
        return (1);
 
    return (0); 
}

int main(int argc, char **argv)
{
    t_args args;
    t_fork *forks;
    t_philo *philos;
    t_monitor *monitor;

    if (validator(&args, argc, argv))
        return (ERRARGS);
    forks = NULL;
    philos = NULL;
    monitor = NULL;
    if (init_all(&philos, &forks, &monitor, &args))
        return (ERRINIT);
    if (args.nb_philos_forks == 1)
    {
        if (create_thread_one_philosopher(&philos, &monitor))
            return (cleanup_all(forks, philos, monitor, args.nb_philos_forks), ERRTHREAD); 
    }
    else
    {
        if (create_threads(&philos, &monitor, args.nb_philos_forks))
            return (cleanup_all(forks, philos, monitor, args.nb_philos_forks), ERRTHREAD); 
    }
    // unit_test(philos, forks, &args);
    return (cleanup_all(forks, philos, monitor, args.nb_philos_forks), EXIT_SUCCESS);
}
