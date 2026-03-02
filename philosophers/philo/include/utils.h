/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:35:07 by omawele           #+#    #+#             */
/*   Updated: 2026/02/22 17:57:58 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

# define TRUE 0
# define FALSE 1

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
    long init_time;
} t_args;

/*
* @brief Structure to create philosophers
*/
typedef struct s_philosophers
{
    pthread_t tid;
    unsigned int index;
    unsigned int tto_eat;
    unsigned int tto_die;
    unsigned int tto_sleep;
    t_fork left_fork;
    t_fork right_fork;
    t_args context;
} t_philo;




void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
long get_time_in_milliseconds(void);

#endif
