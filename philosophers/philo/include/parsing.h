/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:51:48 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 10:31:03 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H


# include "utils.h"
# include "error.h"
# include "free.h"

int validator(t_args *args, int argc, char **argv, long time_start);
int init_all(t_philo **philos, t_fork **forks, t_waiter **waiter, t_args *args);




#endif