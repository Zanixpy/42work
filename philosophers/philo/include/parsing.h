/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:51:48 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 21:53:52 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H


# include "utils.h"
# include "error.h"
# include "free.h"

int validator(t_args *args, int argc, char **argv);
t_fork *init_forks(int nb_forks);
t_philo *init_philosophers(t_args *args, t_fork *forks);




#endif