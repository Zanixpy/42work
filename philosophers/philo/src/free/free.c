/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:12:19 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 20:00:58 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/free.h"

void cleanup_philosophers(t_philo *philos)
{
    free(philos);
}

void cleanup_forks(t_fork *forks)
{
    free(forks);
}

void cleanup_all(t_fork *forks, t_philo *philos)
{
    cleanup_philosophers(philos);
    cleanup_forks(forks);
}