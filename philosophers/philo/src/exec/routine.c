/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/03/10 17:58:56 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
#include <stdio.h>

void psleep(t_philo *philo)
{
    long current_time;

    current_time = get_time_in_milliseconds();
    if (current_time == -1)
        return;
    current_time -= philo->start_time;
    if (should_stop(philo))
        return;
    pthread_mutex_lock(philo->print_mutex);
    printf("%ld %d is sleeping\n", current_time, philo->index);
    pthread_mutex_unlock(philo->print_mutex);
    usleep(philo->args.tto_sleep * 1000);
}

void eat(t_philo *philo)
{
    long current_time;

    current_time = get_time_in_milliseconds();
    if (current_time == -1)
        return;
    current_time -= philo->start_time;
    take_first_fork(philo);
    if (should_stop(philo))
    {
        if (philo->index % 2 == 0)
            pthread_mutex_unlock(&philo->left_fork.locker);
        else
            pthread_mutex_unlock(&philo->right_fork.locker);
        return;
    }
    pthread_mutex_lock(philo->print_mutex);
    printf("%ld %d has taken a fork\n", current_time, philo->index);
    pthread_mutex_unlock(philo->print_mutex);
    take_second_fork(philo);
    if (should_stop(philo))
    {
        pthread_mutex_unlock(&philo->right_fork.locker);
        pthread_mutex_unlock(&philo->left_fork.locker);
        return;
    }
    pthread_mutex_lock(philo->print_mutex);
    printf("%ld %d has taken a fork\n", current_time, philo->index);
    pthread_mutex_unlock(philo->print_mutex);
    pthread_mutex_lock(&philo->lock_last_meal);
    philo->last_meal_time = get_time_in_milliseconds();
    pthread_mutex_unlock(&philo->lock_last_meal);
    if (should_stop(philo))
    {
        pthread_mutex_unlock(&philo->right_fork.locker);
        pthread_mutex_unlock(&philo->left_fork.locker);
        return;
    }
    pthread_mutex_lock(philo->print_mutex);
    printf("%ld %d is eating\n", current_time, philo->index);
    pthread_mutex_unlock(philo->print_mutex);
    usleep(philo->args.tto_eat * 1000);
    pthread_mutex_unlock(&philo->right_fork.locker);
    pthread_mutex_unlock(&philo->left_fork.locker);
}

void think(t_philo *philo)
{
    long current_time;

    current_time = get_time_in_milliseconds();
    if (current_time == -1)
        return;
    current_time -= philo->start_time;
    if (should_stop(philo))
        return;
    pthread_mutex_lock(philo->print_mutex);
    printf("%ld %d is thinking\n", current_time, philo->index);
    pthread_mutex_unlock(philo->print_mutex);
}

void *routine_philosopher(void *args)
{
    t_philo  *philo;
    
    philo = (t_philo *)args;
    while (1) 
    {
        if (should_stop(philo))
            break; 
        eat(philo);
        psleep(philo);
        think(philo);
         
    }
    return ((void *)0);
}
