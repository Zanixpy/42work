/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:12:19 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 14:43:31 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/free.h"

void cleanup_philosophers(t_philo *philos, int size)
{
    (void)size;
    free(philos);
}

void cleanup_forks(t_fork *forks, int size)
{
    (void)size;
    free(forks);
}

void cleanup_all(t_fork *forks, t_philo *philos, int size)
{
    cleanup_philosophers(philos, size);
    cleanup_forks(forks, size);
}