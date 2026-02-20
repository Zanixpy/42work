/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:29:21 by omawele           #+#    #+#             */
/*   Updated: 2026/02/20 21:59:15 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_args args;
    t_fork *forks;
    t_philo *philos;
   
    if (validator(&args, argc, argv))
        return (ERRARGS);
    if (args.nb_philos_forks == 0)
        return (EXIT_SUCCESS);
    forks = init_forks(args.nb_philos_forks);
    if (!forks)
        return (error_init(1));
    philos = init_philosophers(&args, forks);
    if (!philos)
        return (cleanup_forks(forks), error_init(0));
    unit_test(philos, forks, &args);
    cleanup_all(forks, philos);
    return (EXIT_SUCCESS);
}
