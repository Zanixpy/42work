/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/03/05 12:58:18 by omawele          ###   ########.fr       */
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
        if (pthread_mutex_init(&forks[i].locker, NULL) != 0)
        {
            free(forks);
            return (NULL);
        }
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
        philos[i].last_meal_time = 0;
        philos[i].args = *args;
        if (i != 0)
            philos[i].right_fork = forks[i - 1];
        else if (i == 0)
            philos[i].right_fork = forks[args->nb_philos_forks - 1];
        philos[i].left_fork = forks[i];
        i++;
    }
    return (philos);
}

int init_all(t_philo **philos, t_fork **forks, t_args *args)
{
    *forks = init_forks(args->nb_philos_forks);
    if (!(*forks))
        return (error_init(2), 1);
    *philos = init_philosophers(args, *forks);
    if (!(*philos))
        return (cleanup_forks(*forks, args->nb_philos_forks), error_init(3), 1);
    return (0);
}





