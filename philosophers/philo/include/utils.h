/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:35:07 by omawele           #+#    #+#             */
/*   Updated: 2026/03/10 16:43:19 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>


/*
* @brief Structure to create forks for philosophers
*/
typedef struct s_fork
{
    unsigned int index;
    pthread_mutex_t locker;
} t_fork;

/*
* @brief Structure to contain the arguments of main
*/
typedef struct s_args
{
    unsigned int nb_philos_forks;
    unsigned int tto_eat;
    unsigned int tto_die;
    unsigned int tto_sleep;
} t_args;

/*
* @brief Structure to create philosophers
*/
typedef struct s_philosophers
{
    pthread_t tid;
    unsigned int index;
    long last_meal_time;
    long start_time;
    int stop;
    t_args args;
    t_fork left_fork;
    t_fork right_fork;
    pthread_mutex_t *print_mutex;
    pthread_mutex_t *stop_mutex;
    pthread_mutex_t lock_last_meal;
} t_philo;

typedef struct s_monitor
{
    pthread_t tid;
    long start_time;
    t_philo *philos;
    t_args args;
    pthread_mutex_t *lock_last_meal;
    pthread_mutex_t *stop_mutex;
    pthread_mutex_t *print_mutex;
} t_monitor;



void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
long get_time_in_milliseconds(void);
void take_first_fork(t_philo *philo);
void take_second_fork(t_philo *philo);
int	should_stop(t_philo *philo);

#endif
