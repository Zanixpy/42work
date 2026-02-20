/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:48:42 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 15:26:45 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "utils.h"
# define ERRARGS 2
# define ERRINIT 3



/*
* @brief Display and return error if arguments are wrong
* @param code Typifies the type of error, if it's the number of args or args itself
*/
int error_args(int code);

/*
* @brief Display and return error if the initialization step failed
*/
int error_init();


#endif