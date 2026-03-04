/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 17:13:44 by omawele          ###   ########.fr       */
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
    forks = NULL;
    philos = NULL;
    if (init_all(&philos, &forks, &args))
        return (ERRINIT);
    if (create_threads(philos, args.nb_philos_forks))
        return (cleanup_all(forks, philos, args.nb_philos_forks), ERRTHREAD);
    // unit_test(philos, forks, &args);
    return (cleanup_all(forks, philos, args.nb_philos_forks), EXIT_SUCCESS);
}
