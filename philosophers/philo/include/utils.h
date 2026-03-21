/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:35:07 by omawele           #+#    #+#             */
/*   Updated: 2026/03/20 15:02:42 by omawele          ###   ########.fr       */
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
	pthread_mutex_t	locker;
} t_fork;

/*
* @brief Structure to contain the arguments of main
*/
typedef struct s_data
{
    unsigned int size;
    unsigned int tto_eat;
    unsigned int tto_die;
    unsigned int tto_sleep;
    unsigned int eat_count;
	long			start_time;
} t_data;

typedef struct s_mutex
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*stop_mutex;
	pthread_mutex_t	*lock_last_meal;
	pthread_mutex_t	*lock_eat_count;
} t_mutex;

/*
* @brief Structure to create philosophers
*/
typedef struct s_philosophers
{
	pthread_t		tid;
	unsigned int	index;
	long			last_meal_time;
	unsigned int	eat_count;
	int				stop;
	t_data			data;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_mutex 		mutexes;
} t_philo;

typedef struct s_monitor
{
    pthread_t tid;
    t_philo *philos;
    t_data 	data;
	t_mutex mutexes;
} t_monitor;



void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
long get_time_in_milliseconds(void);
size_t ft_strlen(char *s);

int	should_stop(t_philo *philo);
void	precise_sleep(t_philo *philo, long duration_ms);


#endif
