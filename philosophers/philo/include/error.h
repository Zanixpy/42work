/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:48:42 by omawele           #+#    #+#             */
/*   Updated: 2026/03/05 12:23:05 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "utils.h"
# define ERRARGS 2
# define ERRINIT 3
# define ERRTHREAD 4
# define ERRLOCK 5

/*
* @brief Display error if arguments are wrong
* @param code Typifies the type of error, if it's the number of args or args itself
*/
void error_args(int code);

/*
* @brief Display error if the initialization step failed
* @param code Typifies the type of error
*/
void error_init(int code);


#endif