/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_one_philosopher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:36:07 by omawele           #+#    #+#             */
/*   Updated: 2026/03/09 14:37:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void *routine_only_one_philosopher(void *args)
{
    t_philo  *philo;
    int check_eat;
    int check_think;

    check_eat = 0;
    check_think = 0;
    philo = (t_philo *)args;
    while (!philo->stop) 
    {
        eat_only_one_philospher(philo, &check_eat);
        think_only_one_philosopher(philo, &check_think);     
    }
    return ((void *)0);
}

void eat_only_one_philospher(t_philo *philo, int *check_eat)
{
    long current_time;
 
    if (*check_eat)
        return;
    current_time = get_time_in_milliseconds();
    if (current_time == -1)
        return;
    current_time -= philo->start_time;
    *check_eat = 1;
    pthread_mutex_lock(&philo->right_fork.locker);
    pthread_mutex_lock(philo->print_mutex);
    printf("%ld %d has taken a fork\n", current_time, philo->index);
    pthread_mutex_unlock(philo->print_mutex);
    pthread_mutex_unlock(&philo->right_fork.locker);

}

void think_only_one_philosopher(t_philo *philo, int *check_think)
{
    long current_time;
 
    if (*check_think)
        return;
    current_time = get_time_in_milliseconds();
    if (current_time == -1)
        return;
    current_time -= philo->start_time;
    *check_think = 1;
    pthread_mutex_lock(philo->print_mutex);
    printf("%ld %d is thinking\n", current_time, philo->index);
    pthread_mutex_unlock(philo->print_mutex); 
}