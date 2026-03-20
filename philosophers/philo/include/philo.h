/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:32:01 by omawele           #+#    #+#             */
/*   Updated: 2026/03/17 19:08:00 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
** ======================================================
**      INCLUDES SYSTEM
** ======================================================
*/

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

/*
** ======================================================
**      INCLUDES MODULES 
** ======================================================
*/

# include "parsing.h"
# include "utils.h"
# include "error.h"
# include "free.h"
# include "exec.h"

void unit_test(t_philo *philos, t_fork *forks, t_args *args);

int create_threads(t_philo **philos, t_monitor **monitor, int size);
int	create_thread_one_philosopher(t_philo **philos);

#endif