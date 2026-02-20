/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:35:07 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 16:07:06 by omawele          ###   ########.fr       */
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
* @brief Structure to create philosophers
*/
typedef struct s_philosophers
{
    pthread_t tid;
    int index;
    int tto_eat;
    int tto_die;
    int tto_sleep;
    t_fork left_fork;
    t_fork right_fork;
} t_philo;

/*
* @brief Structure to contain the arguments of main
*/
typedef struct s_args
{
    int nb_philos_forks;
    int tto_eat;
    int tto_die;
    int tto_sleep;
} t_args;


void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);

#endif
