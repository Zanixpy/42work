/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 22:09:38 by omawele           #+#    #+#             */
/*   Updated: 2026/04/04 23:40:07 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "error.h"
# include "utils.h"

void	*routine_monitor(void *args);
int		dead(t_monitor *monitor, int index);
void	end_simulation(t_monitor *monitor);
int	check_eat_times(t_monitor *monitor, int has_eatean_count);

void	*routine_philosophers(void *args);
void	*routine_philosopher(void *args);

int		take_forks(t_philo *philo);
int		should_stop(t_philo *philo);
void	release_forks(t_philo *philo);
void	release_one_fork(t_philo *philo);

void	psleep(t_philo *philo);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	eat_one(t_philo *philo, int *check_eat);
void	think_one(t_philo *philo, int *check_think);

#endif