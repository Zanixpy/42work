/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:32:01 by omawele           #+#    #+#             */
/*   Updated: 2026/02/02 20:41:09 by omawele          ###   ########.fr       */
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

# define EXIT_FAIL_ARGS 2



// Sys time structure




// Arguments validation

int args_validation(int argc, char **argv);

// Functs utils

unsigned long ft_strlen(const char *s);
int	strcmp_int_limit(char *s);

#endif