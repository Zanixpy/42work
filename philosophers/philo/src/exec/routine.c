/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:17 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 11:02:59 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void print_philosopher_state(t_philo *philo, int mode)
{
    long current_time;
    long final_time;
    
    current_time = get_time_in_milliseconds();
    if (current_time == -1)
        return ;
    final_time = current_time - philo->is_eating;
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

int eat(t_philo *philo)
{
    (void)philo;
    // if (philo->prev->right_fork_taken)
    // {
    //     printf("Main index : %d ; BLOQUER, prev index : %d \n", philo->index, philo->prev->index);
    //     return (FALSE);        
    // }
    // pthread_mutex_lock(&philo->right_fork.locker);
    // philo->right_fork_taken = 1;
    // print_philosopher_state(philo, 1);
    // if (philo->next->left_fork_taken)
    // {
    //     pthread_mutex_unlock(&philo->right_fork.locker);
    //     philo->right_fork_taken = 0;     
    //     return (FALSE);  
    // }
    // pthread_mutex_lock(&philo->left_fork.locker);
    // philo->left_fork_taken = 1;
    // print_philosopher_state(philo, 1);
    // print_philosopher_state(philo, 2);
    // philo->is_eating = 1;
    // usleep(philo->context.tto_eat * 1000);
    // pthread_mutex_unlock(&philo->right_fork.locker);
    // philo->right_fork_taken = 0;     
    // pthread_mutex_unlock(&philo->left_fork.locker);
    // philo->left_fork_taken = 0;
    return (TRUE);
}

int psleep(t_philo *philo)
{
    if (!philo->is_eating)
        return (FALSE);
    philo->is_eating = 0;
    philo->is_thinking = 0;
    print_philosopher_state(philo, 3);
    // usleep(philo->context.tto_sleep * 1000);
    return (TRUE);
}

int think(t_philo *philo)
{
    if (philo->is_eating || philo->is_thinking)
        return (FALSE);
    philo->is_thinking = 1;
    print_philosopher_state(philo, 4);
    return (TRUE);
}

int dead(t_philo *philo, long *time)
{
    long diff;

    (void)philo;
    diff = get_time_in_milliseconds();
    if (diff == -1)
        return (FALSE);
    
    // if (diff - (*time) > (long)philo->context.tto_die)
    // {
    //     print_philosopher_state(philo, 5);
    //     return (FALSE);
    // }
    *time = diff;
    return (TRUE);
}

void *routine_philosopher(void *args)
{
    t_waiter *waiter;
    t_philo  philo;
    int index;
    // long time;

    waiter = (t_waiter *)args;
    index = waiter->index_philo;
    philo = waiter->philos[index];
    // philo = (t_philo *)args;
    // time = get_time_in_milliseconds();
    printf("index : %d\n", philo.index);
    printf("left_fork_taken : %d\n", philo.left_fork_taken);
    printf("right_fork_taken : %d\n", philo.right_fork_taken);
    printf("is_thinking : %d\n", philo.is_thinking);
    printf("is_eating : %d\n", philo.is_eating);
    printf("left_fork index : %d\n", philo.left_fork.index);
    printf("right_fork index : %d\n", philo.right_fork.index);
    // while (1) 
    // {
    //     // if (!philo->prev->right_fork_taken || !philo->next->left_fork_taken)
    //     //     eat(philo);
    //     psleep(philo);
    //     think(philo);
    //     if (dead(philo, &time))
    //         break;
    // }
    // pthread_detach(philo->tid);
    return (args);
}
