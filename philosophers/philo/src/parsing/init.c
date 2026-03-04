/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 11:12:54 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static t_fork *init_forks(int nb_forks)
{
    t_fork *forks;
    int i;

    forks = malloc(nb_forks * sizeof(t_fork));
    if (!forks)
        return (NULL);
    i = 0;
    while (i < nb_forks)
    {
        forks[i].index = i;
        pthread_mutex_init(&forks[i].locker, NULL);
        i++;
    }
    return (forks);
}

static t_philo *init_philosophers(t_args *args, t_fork *forks)
{
    t_philo *philos;
    unsigned int i;
    
    philos = malloc(args->nb_philos_forks * sizeof(t_philo));
    if (!philos)
        return (NULL);
    i = 0;
    while (i < args->nb_philos_forks)
    {
        philos[i].index = i;
        philos[i].left_fork_taken = 0;
        philos[i].right_fork_taken = 0;
        philos[i].is_thinking = 0;
        philos[i].is_eating = 0;
        philos[i].last_meal_time = 0;
        if (i != 0)
            philos[i].right_fork = forks[i - 1];
        else if (i == 0)
            philos[i].right_fork = forks[args->nb_philos_forks - 1];
        philos[i].left_fork = forks[i];
        i++;
    }
    return (philos);
}

static t_waiter *init_waiter(t_philo *philos, t_args *args)
{
    t_waiter *waiter;

    waiter = malloc(1 * sizeof(t_waiter));
    if (!waiter)
        return (NULL);
    waiter->philos = philos;
    waiter->context = *args;
    return (waiter); 
}

int init_all(t_philo **philos, t_fork **forks, t_waiter **waiter, t_args *args)
{
    *forks = init_forks(args->nb_philos_forks);
    if (!(*forks))
        return (error_init(1));
    *philos = init_philosophers(args, *forks);
    if (!(*philos))
        return (cleanup_forks(*forks, args->nb_philos_forks), error_init(2));
    *waiter = init_waiter(*philos, args);
    if (!(*waiter))
        return (cleanup_all(*forks, *philos, *waiter, args->nb_philos_forks), error_init(3));
    return (TRUE);
}





