/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:38 by omawele           #+#    #+#             */
/*   Updated: 2026/03/09 16:05:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "utils.h"
# include "error.h"



void *routine_philosopher(void *args);
void psleep(t_philo *philo);
void eat(t_philo *philo);
void think(t_philo *philo);
// int dead(t_philo *philo);
void eat_only_one_philospher(t_philo *philo, int *check_eat);
void *routine_only_one_philosopher(void *args);
void think_only_one_philosopher(t_philo *philo, int *check_think);
int create_monitor(t_monitor **monitor);
void *routine_monitor(void *args);
void end_simulation(t_monitor *monitor);

#endif