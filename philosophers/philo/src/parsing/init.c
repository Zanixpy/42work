/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/03/09 15:39:14 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include <stdlib.h>
#include <string.h>


static pthread_mutex_t *create_mutex(void)
{
    pthread_mutex_t *mutex;
    
    mutex = malloc(sizeof(pthread_mutex_t));
    if (!mutex)
        return (NULL);
    if (pthread_mutex_init(mutex, NULL) != 0)
        return (free(mutex), NULL);
    return (mutex);
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
        if (pthread_mutex_init(&forks[i].locker, NULL) != 0)
            return (cleanup_forks(forks, nb_forks), NULL);
        i++;
    }
    return (forks);
}

static t_philo *init_philosophers(t_args *args, t_fork *forks)
{
    t_philo *philos;
    pthread_mutex_t *print_mutex;
    unsigned int i;
    
    philos = malloc(args->nb_philos_forks * sizeof(t_philo));
    if (!philos)
        return (NULL);
    print_mutex = create_mutex();
    if (!print_mutex)
        return (free(philos), NULL);
    i = -1;
    while (++i < args->nb_philos_forks)
    {
        philos[i].index = i;
        philos[i].last_meal_time = 0;
        philos[i].args = *args;
        philos[i].print_mutex = print_mutex;
        philos[i].stop = 0;
        if (i != 0)
            philos[i].right_fork = forks[i - 1];
        else if (i == 0)
            philos[i].right_fork = forks[args->nb_philos_forks - 1];
        philos[i].left_fork = forks[i];
    }
    return (philos);
}

static t_philo *init_only_one_philosophers(t_args *args, t_fork *forks)
{
    t_philo *philos;
    pthread_mutex_t *print_mutex;
    
    philos = malloc(sizeof(t_philo));
    if (!philos)
        return (NULL);
    print_mutex = create_mutex();
    if (!print_mutex)
        return (free(philos), NULL);
    philos[0].index = 0;
    philos[0].last_meal_time = 0;
    philos[0].args = *args;
    philos[0].print_mutex = print_mutex;
    philos[0].right_fork = forks[0];
    philos[0].stop = 0;
    return (philos);
}

int init_all(t_philo **philos, t_fork **forks, t_monitor **monitor, t_args *args)
{    
    *forks = init_forks(args->nb_philos_forks);
    if (!(*forks))
        return (error_init(1), 1);
    if (args->nb_philos_forks == 1)
        *philos = init_only_one_philosophers(args, *forks);
    else
        *philos = init_philosophers(args, *forks);
    if (!(*philos))
        return (cleanup_forks(*forks, args->nb_philos_forks), error_init(2), 1);
    *monitor = malloc((sizeof(t_monitor)));
    if (!(*monitor))
        return (cleanup_all(*forks, *philos, *monitor, args->nb_philos_forks), error_init(3), 1);
    (*monitor)->philos = philos;
    (*monitor)->args = *args;
    (*monitor)->lock_last_meal = create_mutex();
    (*monitor)->print_mutex = (*philos)->print_mutex;
    if (!(*monitor)->lock_last_meal)
        return (cleanup_all(*forks, *philos, *monitor, args->nb_philos_forks), error_init(3), 1);
    return (0);
}





