/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/02/22 18:15:25 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int create_threads(t_philo *philos, int size)
{
    int i;
    long time;

    i = 0;
    time = get_time_in_milliseconds();
    while (i < size) 
    {
        philos[i].context.init_time = time;
        if (pthread_create(&philos[i].tid, NULL, &routine_philosopher, (void *)&philos[i]) != 0)
            return (FALSE);
        i++;
    }
    i = 0;
    while (i < size) 
    {
        if (pthread_join(philos[i].tid, NULL) != 0)
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
   
    if (validator(&args, argc, argv))
        return (ERRARGS);
    if (args.nb_philos_forks == 0 || args.nb_philos_forks == 1)
        return (EXIT_SUCCESS);
    forks = init_forks(args.nb_philos_forks);
    if (!forks)
        return (error_init(1));
    philos = init_philosophers(&args, forks);
    if (!philos)
        return (cleanup_forks(forks), error_init(0));
    if (create_threads(philos, args.nb_philos_forks))
        return (cleanup_all(forks, philos), ERRTHREAD);
    // unit_test(philos, forks, &args);
    return (cleanup_all(forks, philos), EXIT_SUCCESS);
}
