/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:49:59 by omawele           #+#    #+#             */
/*   Updated: 2026/03/10 18:07:03 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

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

static t_philo *init_philosophers(t_args *args, t_fork *forks, pthread_mutex_t *print_mutex, pthread_mutex_t *stop_mutex)
{
    t_philo *philos;
    unsigned int i;
    
    philos = malloc(args->nb_philos_forks * sizeof(t_philo));
    if (!philos)
        return (NULL);
    i = -1;
    while (++i < args->nb_philos_forks)
    {
        philos[i].index = i;
        philos[i].last_meal_time = 0;
        philos[i].args = *args;
        philos[i].print_mutex = print_mutex;
        philos[i].stop_mutex = stop_mutex;
        philos[i].stop = 0;
        if (pthread_mutex_init(&philos[i].lock_last_meal, NULL) != 0)
            return (cleanup_philosophers(philos, i), NULL);
        if (i == 0)
            philos[i].right_fork = forks[args->nb_philos_forks - 1];
        else
            philos[i].right_fork = forks[i - 1];
        philos[i].left_fork = forks[i];
    }
    return (philos);
}

static t_philo *init_only_one_philosophers(t_args *args, t_fork *forks, pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
    t_philo *philo;
    
    philo = malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    philo[0].index = 0;
    philo[0].last_meal_time = 0;
    philo[0].args = *args;
    philo[0].print_mutex = *print_mutex;
    philo[0].stop_mutex = *stop_mutex;
    philo[0].right_fork = forks[0];
    philo[0].stop = 0;
    if (pthread_mutex_init(&philo[0].lock_last_meal, NULL) != 0)
        return (cleanup_philosophers(philo, 1), NULL);  
    return (philo);
}

int init_all(t_philo **philos, t_fork **forks, t_monitor **monitor, t_args *args)
{
    pthread_mutex_t *print_mutex;
    pthread_mutex_t *stop_mutex;
    
    *forks = init_forks(args->nb_philos_forks);
    if (!(*forks))
        return (error_init(1), 1);
    print_mutex = create_mutex();
    if (!print_mutex)
        return (cleanup_forks(*forks, args->nb_philos_forks), error_init(2), 1);
    stop_mutex = create_mutex();
    if (!stop_mutex)
        return (cleanup_forks(*forks, args->nb_philos_forks), error_init(2), 1);        
    if (args->nb_philos_forks == 1)
        *philos = init_only_one_philosophers(args, *forks, &print_mutex, &stop_mutex);
    else
        *philos = init_philosophers(args, *forks, print_mutex, stop_mutex);
    if (!(*philos))
        return (cleanup_forks(*forks, args->nb_philos_forks), error_init(2), 1);
    *monitor = malloc((sizeof(t_monitor)));
    if (!(*monitor))
        return (cleanup_all(*forks, *philos, *monitor, args->nb_philos_forks), error_init(3), 1);
    (*monitor)->philos = *philos;
    (*monitor)->args = *args;
    (*monitor)->print_mutex = print_mutex;
    (*monitor)->stop_mutex = stop_mutex;
    return (0);
}





