/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/03/05 13:00:29 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int create_threads(t_philo *philos, int size)
{
    int i;

    i = 0;
    while (i < size) 
    {
        if (pthread_create(&philos[i].tid, NULL, &routine_philosopher, (void *)&philos[i]) != 0)
            return (1);
        i++; 
    }
    i = 0;
    while (i < size) 
    {
        if (pthread_join(philos[i].tid, NULL) != 0)
            return (1);
        i++;
    }
    return (0); 
}

int main(int argc, char **argv)
{
    t_args args;
    t_fork *forks;
    t_philo *philos;
    long time_start;

    time_start = get_time_in_milliseconds();
    if (time_start == -1)
        return (EXIT_FAILURE);
    if (validator(&args, argc, argv, time_start))
        return (ERRARGS);
    forks = NULL;
    philos = NULL;
    if (init_all(&philos, &forks, &args))
        return (ERRINIT);
    if (create_threads(philos, args.nb_philos_forks))
        return (cleanup_all(forks, philos, args.nb_philos_forks), ERRTHREAD);
    printf("ICI\n");
    // unit_test(philos, forks, &args);
    return (cleanup_all(forks, philos, args.nb_philos_forks), EXIT_SUCCESS);
}
