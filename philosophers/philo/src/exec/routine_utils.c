/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:35:19 by omawele           #+#    #+#             */
/*   Updated: 2026/03/11 12:37:15 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/exec.h"

void unlock_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->right_fork.locker);
    pthread_mutex_unlock(&philo->left_fork.locker);
}