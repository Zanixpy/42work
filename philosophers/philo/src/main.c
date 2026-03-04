/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 11:22:15 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int create_threads(t_waiter *waiter)
{
    int i;
    int size;

    i = 0;
    size = waiter->context.nb_philos_forks;
    while (i < size) 
    {
        if (pthread_create(&waiter->philos[i].tid, NULL, &routine_philosopher, (void *)waiter) != 0)
            return (FALSE);
        i++;
    }
    i = 0;
    while (i < size) 
    {
        if (pthread_join(waiter->philos[i].tid, NULL) != 0)
            return (FALSE);
        i++;
    }
    return (TRUE); 
}


int main(int argc, char **argv)
{
    t_args args;
    t_fork *forks;
    t_philo *philos;
    t_waiter *waiter;
    long time_start;

    time_start = get_time_in_milliseconds();
    if (validator(&args, argc, argv, time_start))
        return (ERRARGS);
    if (args.nb_philos_forks == 0 || args.nb_philos_forks == 1)
        return (EXIT_SUCCESS);
    forks = NULL;
    philos = NULL;
    waiter = NULL;
    if (init_all(&philos, &forks, &waiter, &args))
        return (ERRINIT);
    if (create_threads(waiter))
        return (cleanup_all(forks, philos, waiter, args.nb_philos_forks), ERRTHREAD);
    // unit_test(philos, forks, waiter, &args);
    return (cleanup_all(forks, philos, waiter,args.nb_philos_forks), EXIT_SUCCESS);
}
