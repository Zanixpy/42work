/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:16:29 by omawele           #+#    #+#             */
/*   Updated: 2026/03/04 16:10:56 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

#include "utils.h"

void cleanup_philosophers(t_philo *philos);
void cleanup_forks(t_fork *forks, int size);
void cleanup_all(t_fork *forks, t_philo *philos, int size);


#endif