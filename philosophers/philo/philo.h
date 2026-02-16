/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:32:01 by omawele           #+#    #+#             */
/*   Updated: 2026/02/16 21:07:43 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

// Code errors

typedef struct s_fork
{
    unsigned int index;
    pthread_mutex_t locker;
} t_fork;

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

typedef struct s_args
{
    int nb_philos_forks;
    int tto_eat;
    int tto_die;
    int tto_sleep;
} t_args;





// Sys time structure

void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
void convert_args_in_int(t_args *args, char **argv);

// Arguments validation

int args_checker(int argc, char **argv);

// Functs utils

#endif