/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/02/02 20:43:24 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	print_errors(int code)
{
	if (code == EXIT_FAILURE)
		write(2, "error: fault occured somewhere\n", 32);
	else if (code == EXIT_FAIL_ARGS)
		write(2,"args: more or less than 4\n", 27);
    return (code);
}


int main(int argc, char **argv)
{
    int carg;

    if (argc != 5)
        return (print_errors(EXIT_FAIL_ARGS));
    
    
    return (EXIT_SUCCESS);
}