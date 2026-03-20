/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:21:49 by omawele           #+#    #+#             */
/*   Updated: 2026/03/17 12:11:11 by omawele          ###   ########.fr       */
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
        printf("last_meal_time : %ld\n", philos[n].last_meal_time);    
        printf("left_fork index : %d\n", philos[n].left_fork->index);
        printf("right_fork index : %d\n", philos[n].right_fork->index);
        printf("tto_eat : %d\n", philos[n].args.tto_eat);
        printf("tto_die : %d\n", philos[n].args.tto_die);
        printf("tto_sleep : %d\n", philos[n].args.tto_sleep);
        printf("time_start : %ld\n", philos[n].start_time);
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
    printf("nb_philos_forks : %d\n", args->size);
    printf("tto_eat : %d\n", args->tto_eat);
    printf("tto_die : %d\n", args->tto_die);
    printf("tto_sleep : %d\n", args->tto_sleep);
    printf("========================\n");
}

void unit_test(t_philo *philos, t_fork *forks, t_args *args)
{
    unit_test_args(args);
    unit_test_philos(philos, args->size);
    unit_test_forks(forks, args->size);
}