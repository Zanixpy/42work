/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:21:49 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 10:13:40 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void unit_test_philos(t_philo *philos, int size)
{
    int n = 0;
    
    printf("====== PHILO TEST ======\n");
    while (n < size) 
    {
        printf("index : %d\n", philos[n].index);
        printf("left_fork_taken : %d\n", philos[n].left_fork_taken);
        printf("right_fork_taken : %d\n", philos[n].right_fork_taken);
        printf("is_thinking : %d\n", philos[n].is_thinking);
        printf("is_eating : %d\n", philos[n].is_eating);
        printf("left_fork index : %d\n", philos[n].left_fork.index);
        printf("right_fork index : %d\n", philos[n].right_fork.index);
        printf("\n");
        n++;
    }
    printf("========================\n");
}

void unit_test_forks(t_fork *forks, int size)
{
    int n = 0;
    
    printf("====== FORKS TEST ======\n");
    while (n < size) 
    {
        printf("index : %d\n", forks[n].index);
        n++;
    }
    printf("========================\n");
}

void unit_test_args(t_args *args)
{
    printf("====== ARGS TEST ======\n");
    printf("nb_philos_forks : %d\n", args->nb_philos_forks);
    printf("tto_eat : %d\n", args->tto_eat);
    printf("tto_die : %d\n", args->tto_die);
    printf("tto_sleep : %d\n", args->tto_sleep);
    printf("========================\n");
}

void unit_test_waiter(t_waiter *waiter)
{
    printf("====== WAITER TEST ======\n");
    printf("nb_philos_forks : %d\n", waiter->context.nb_philos_forks);
    printf("tto_eat : %d\n", waiter->context.tto_eat);
    printf("tto_die : %d\n", waiter->context.tto_die);
    printf("tto_sleep : %d\n", waiter->context.tto_sleep);
    printf("index : %d\n", waiter->philos->index);
    printf("left_fork_taken : %d\n", waiter->philos->left_fork_taken);
    printf("right_fork_taken : %d\n", waiter->philos->right_fork_taken);
    printf("is_thinking : %d\n", waiter->philos->is_thinking);
    printf("is_eating : %d\n", waiter->philos->is_eating);
    printf("left_fork index : %d\n", waiter->philos->left_fork.index);
    printf("right_fork index : %d\n", waiter->philos->right_fork.index); 
    printf("========================\n");
}

void unit_test(t_philo *philos, t_fork *forks, t_waiter *waiter, t_args *args)
{
    unit_test_args(args);
    unit_test_philos(philos, args->nb_philos_forks);
    unit_test_forks(forks, args->nb_philos_forks);
    unit_test_waiter(waiter);
}