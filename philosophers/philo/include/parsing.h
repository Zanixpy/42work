/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:51:48 by omawele           #+#    #+#             */
/*   Updated: 2026/03/17 20:23:46 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H


# include "utils.h"
# include "error.h"
# include "free.h"

int validator(t_args *args, int argc, char **argv);
int init_all(t_philo **philos, t_fork **forks, t_monitor **monitor, t_args *args);
t_philo	*init_philosophers(t_args *args, t_fork *forks,
			pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex,
			pthread_mutex_t **forks_mutex);
t_philo	*malloc_philosophers(t_args *args, t_fork *forks,
			pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex,
			pthread_mutex_t **forks_mutex);
t_philo	*malloc_one_philosopher(t_args *args, t_fork *forks,
			pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex,
			pthread_mutex_t **forks_mutex);
t_monitor *init_monitor(t_philo **philos, t_args *args, pthread_mutex_t **print_mutex, pthread_mutex_t **stop_mutex);
t_fork	*init_forks(int nb_forks);




#endif
