/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 16:37:11 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_args args;
    t_fork forks;
    t_philo philos;
    
    if (validator(argc,argv))
        return (EXIT_FAILURE);
    if (init_all(&forks, &philos, &args, argv))
        return (EXIT_FAILURE);
    unit_test(&philos, &forks, &args);
    cleanup_all(&forks, &philos, args.nb_philos_forks);
    return (EXIT_SUCCESS);
}
