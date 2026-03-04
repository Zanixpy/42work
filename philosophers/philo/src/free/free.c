/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:12:19 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 09:57:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/free.h"

void cleanup_philosophers(t_philo *philos)
{
    if (philos)
        free(philos);
}

void cleanup_forks(t_fork *forks, int size)
{
    int i;

    if (!forks)
        return;
    i = 0;
    while (i < size) 
    {
        pthread_mutex_destroy(&forks[i].locker);
        i++;
    }
    free(forks);
}

void cleanup_waiter(t_waiter *waiter)
{
    if (waiter)
        free(waiter);
}

void cleanup_all(t_fork *forks, t_philo *philos, t_waiter *waiter, int size)
{
    cleanup_philosophers(philos);
    cleanup_forks(forks, size);
    cleanup_waiter(waiter);
}