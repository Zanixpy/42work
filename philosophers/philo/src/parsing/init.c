/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 17:12:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include <string.h>

static void set_neighbors_philosphers(t_philo *philos, int size)
{
    int i;

    i = 0;
    if (size == 2)
    {
        philos[i].prev = NULL;
        philos[i].next = &philos[i + 1];
        philos[i + 1].prev = &philos[i];
        philos[i + 1].next = NULL;
        return;
    }
    while (i < size) 
    {
        if (i == 0)
            philos[i].prev = &philos[size - 1];
        else if (i == size - 1)
            philos[i].next = &philos[0];
        if (i != 0)
            philos[i].prev = &philos[i - 1];
        if (i != size - 1)
            philos[i].next = &philos[i + 1];
        i++;
    }    
}

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
    set_neighbors_philosphers(philos, args->nb_philos_forks);
    return (philos);
}

int init_all(t_philo **philos, t_fork **forks, t_args *args)
{
    *forks = init_forks(args->nb_philos_forks);
    if (!(*forks))
        return (error_init(1));
    *philos = init_philosophers(args, *forks);
    if (!(*philos))
        return (cleanup_forks(*forks, args->nb_philos_forks), error_init(0));
    return (TRUE);
}





