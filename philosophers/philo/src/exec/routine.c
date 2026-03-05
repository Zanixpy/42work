/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/03/05 12:59:11 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void print_philosopher_state(t_philo *philo, int mode)
{
    long current_time;
    
    current_time = get_time_in_milliseconds();
    if (current_time == -1)
        return;
    current_time -= philo->args.time_start;
    if (mode == 1)
        printf("%ld %d has taken a fork\n", current_time, philo->index);
    else if (mode == 2)
        printf("%ld %d is eating\n", current_time, philo->index);
    else if (mode == 3)
        printf("%ld %d is sleeping\n", current_time, philo->index);
    else if (mode == 4)
        printf("%ld %d is thinking\n", current_time, philo->index);
    else if (mode == 5)
        printf("%ld %d died\n", current_time, philo->index);   
}


void psleep(t_philo *philo)
{
    print_philosopher_state(philo, 3);
    usleep(philo->args.tto_sleep * 1000);  
}

void eat(t_philo *philo)
{
    if (philo->index % 2 == 0)
        pthread_mutex_lock(&philo->left_fork.locker);
    else
        pthread_mutex_lock(&philo->right_fork.locker);
    print_philosopher_state(philo, 1);
    if (philo->index % 2 == 0)
        pthread_mutex_lock(&philo->right_fork.locker);
    else
        pthread_mutex_lock(&philo->left_fork.locker);
    print_philosopher_state(philo, 1);
    print_philosopher_state(philo, 2);
    usleep(philo->args.tto_eat * 1000);
    pthread_mutex_unlock(&philo->right_fork.locker);
    pthread_mutex_unlock(&philo->left_fork.locker);
    philo->last_meal_time = get_time_in_milliseconds();
    psleep(philo);
}

void think(t_philo *philo)
{
    print_philosopher_state(philo, 4);
}

int dead(t_philo *philo)
{
    long diff;

    diff = get_time_in_milliseconds();
    if (diff == -1)
        return (1);
    if (philo->last_meal_time - diff >= philo->args.tto_die * 1000)
    {
        print_philosopher_state(philo, 5);
        return (1);
    }
    return (0);
}

void *routine_philosopher(void *args)
{
    t_philo  *philo;
    
    philo = (t_philo *)args;
    while (1) 
    {
        eat(philo);
        think(philo);
        if (dead(philo))
            break;
    }
    return ((void *)0);
}
