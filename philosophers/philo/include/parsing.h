/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:51:48 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 16:12:31 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H


# include "utils.h"
# include "error.h"
# include "free.h"


int init_all(t_fork *forks, t_philo *philos, t_args *args, char **argv);
int validator(int argc, char **argv);




#endif