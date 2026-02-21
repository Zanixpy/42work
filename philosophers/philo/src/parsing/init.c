/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/02/21 21:35:39 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include <string.h>

t_fork *init_forks(int nb_forks)
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

t_philo *init_philosophers(t_args *args, t_fork *forks)
{
    t_philo *philos;
    unsigned int i;
    
    philos = malloc(args->nb_philos_forks * sizeof(t_philo));
    if (!philos)
        return (NULL);
    i = 0;
    philos[i].right_fork.index = -1;
    while (i < args->nb_philos_forks)
    {
        philos[i].index = i;
        philos[i].tto_die = args->tto_die;
        philos[i].tto_eat = args->tto_eat;
        philos[i].tto_sleep = args->tto_sleep;
        if (i != 0)
            philos[i].right_fork = forks[i - 1];
        else if (i == 0 && args->nb_philos_forks > 1)
            philos[i].right_fork = forks[args->nb_philos_forks - 1];
        philos[i].left_fork = forks[i];
        i++;
    }
    return (philos);
}





