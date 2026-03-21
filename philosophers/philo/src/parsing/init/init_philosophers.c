/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:16:55 by omawele           #+#    #+#             */
/*   Updated: 2026/03/20 15:35:30 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parsing.h"

t_philo	*init_philosophers(t_data *data, t_fork *forks, pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
    t_philo	*philo;
    int i;

    philo = malloc(sizeof(t_philo));
    if (!philo)
        return (NULL);
    i = 0;
    while (i < data->size)
    {
        philo[i].index = i + 1;
        philo[i].data= *data;
        philo[i].mutexes.print_mutex = *print_mutex;
            philo[i].mut = *stop_mutex;
            philo[i].stop = 0;
            philo[i].eat_count = 0;
            if (pthread_mutex_init(&philo[i].lock_last_meal, NULL) != 0)
                return (free_philos(philo, i), NULL);
            if (pthread_mutex_init(&philo[i].lock_eat_count, NULL) != 0)
                return (free_philos(philo, i), NULL);
            if (i == 0)
                philo[i].right_fork = &forks[args->size - 1];
            else
                philo[i].right_fork = &forks[i - 1];
            philo[i].left_fork = &forks[i];
    } 
}


void set_data(t_data *data, t_fork *forks, pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex)
{
    int i;

    i = 0;

    
}



int set_personnal_mutexes(t_philo *philo)



t_philo	*malloc_philosophers(t_args *args, t_fork *forks,
    pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex,)
{
t_philo			*philos;
unsigned int	i;

philos = malloc(args->size * sizeof(t_philo));
if (!philos)
    return (NULL);
i = -1;
while (++i < args->size)
{
    philos[i].index = i + 1;
    philos[i].last_meal_time = 0;
    philos[i].args = *args;
    philos[i].print_mutex = *print_mutex;
    philos[i].stop_mutex = *stop_mutex;
    philos[i].stop = 0;
    philos[i].eat_count = 0;
    if (pthread_mutex_init(&philos[i].lock_last_meal, NULL) != 0)
        return (free_philos(philos, i), NULL);
    if (pthread_mutex_init(&philos[i].lock_eat_count, NULL) != 0)
        return (free_philos(philos, i), NULL);
    if (i == 0)
        philos[i].right_fork = &forks[args->size - 1];
    else
        philos[i].right_fork = &forks[i - 1];
    philos[i].left_fork = &forks[i];
}
return (philos);
}

t_philo	*malloc_one_philosopher(t_args *args, t_fork *forks,
    pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex,
    pthread_mutex_t **forks_mutex)
{
t_philo	*philo;

philo = malloc(sizeof(t_philo));
if (!philo)
    return (NULL);
philo[0].index = 1;
philo[0].last_meal_time = 0;
philo[0].args = *args;
philo[0].print_mutex = *print_mutex;
philo[0].stop_mutex = *stop_mutex;
philo[0].left_fork = &forks[0];
philo[0].right_fork = &forks[0];
philo[0].stop = 0;
philo[0].eat_count = 0;
if (pthread_mutex_init(&philo[0].lock_last_meal, NULL) != 0)
    return (free_philos(philo, 1), NULL);
if (pthread_mutex_init(&philo[0].lock_eat_count, NULL) != 0)
{
    return (free_philos(philo, 1), NULL);      
}
return (philo);
}