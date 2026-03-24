/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:32:01 by omawele           #+#    #+#             */
/*   Updated: 2026/03/22 21:47:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** ======================================================
**      INCLUDES SYSTEM
** ======================================================
*/

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*
** ======================================================
**      INCLUDES MODULES
** ======================================================
*/

# include "error.h"
# include "exec.h"
# include "free.h"
# include "parsing.h"
# include "utils.h"

void	unit_test(t_philo *philos, t_fork *forks, t_data *data);

int		create_threads(t_philo **philos, t_monitor **monitor, int size);
int		create_thread_one_philosopher(t_philo **philos);

#endif