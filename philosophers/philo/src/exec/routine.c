/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/02/21 22:44:23 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void print_philosopher_state(unsigned int index, int mode)
{
    struct timeval current_time;
    
    if (gettimeofday(&current_time, NULL) == -1)
        return ;
    if (mode == 1)
        printf("%ld %d has taken a fork\n", current_time.tv_sec, index);
    else if (mode == 2)
        printf("%ld %d is eating\n", current_time.tv_sec, index);
    else if (mode == 3)
        printf("%ld %d is sleeping\n", current_time.tv_sec, index);
    else if (mode == 4)
        printf("%ld %d is thinking\n", current_time.tv_sec, index);
    else if (mode == 5)
        printf("%ld %d died\n", current_time.tv_sec, index);   
}

void eating_step(t_philo *philos)
{
    if (pthread_mutex_lock(&philos->right_fork.locker) != 0)
        return;
    
    
    
    
}


void *routine_philosopher(void *args)
{
    t_philo *philos;

    philos = (t_philo *)args;

    while (1) 
    {
         
    }
    usleep(1000000);
    return (args);
}