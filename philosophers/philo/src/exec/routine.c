/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/02/22 18:07:27 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"
#include <stdio.h>

void print_philosopher_state(t_philo *philo, int mode)
{
    long current_time;
    long final_time;
    
    current_time = get_time_in_milliseconds();
    if (current_time == -1)
        return ;
    final_time = current_time - philo->context.init_time;
    if (mode == 1)
        printf("%lu %d has taken a fork\n", final_time, philo->index);
    else if (mode == 2)
        printf("%lu %d is eating\n", final_time, philo->index);
    else if (mode == 3)
        printf("%lu %d is sleeping\n", final_time, philo->index);
    else if (mode == 4)
        printf("%lu %d is thinking\n", final_time, philo->index);
    else if (mode == 5)
        printf("%lu %d died\n", final_time, philo->index);   
}

int eating_step(t_philo *philos)
{
    if (pthread_mutex_lock(&philos->right_fork.locker) != 0)
        return (FALSE);
    print_philosopher_state(philos, 1);
    if (pthread_mutex_lock(&philos->left_fork.locker) != 0)
        return (FALSE);
    print_philosopher_state(philos, 1);
    print_philosopher_state(philos, 2);
    usleep(philos->tto_eat);
    if (pthread_mutex_unlock(&philos->right_fork.locker) != 0)
        return (FALSE);
    if (pthread_mutex_unlock(&philos->left_fork.locker) != 0)
        return (FALSE);
    print_philosopher_state(philos, 3);
    usleep(philos->tto_sleep);
    philos->tto_die = philos->context.tto_die;
    return (TRUE); 
}


void *routine_philosopher(void *args)
{
    t_philo *philos;

    philos = (t_philo *)args;

    while (philos->tto_die) 
    {
        if (eating_step(philos))
            break;
        philos->tto_die--;
    }
    if (philos->tto_die > 0)
        printf("%d tried to take a fork or smth\n", philos->index); 
    else
        print_philosopher_state(philos, 5);  
    return (args);
}