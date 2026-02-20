/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:32:01 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 16:36:06 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


/*
** ===========================
**      INCLUDES SYSTEM
** ===========================
*/

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

/*
** ===========================
**      INCLUDES MODULES 
** ===========================
*/

# include "parsing.h"
# include "utils.h"
# include "error.h"
# include "free.h"

void unit_test(t_philo *philos, t_fork *forks, t_args *args);

#endif