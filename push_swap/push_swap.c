/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:53:03 by omawele           #+#    #+#             */
/*   Updated: 2025/12/18 22:03:26 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int error(int code)
{
    write(2, "Error\n", 6);
    if (code == 1)
        write(2, "No arguments or only one argument\n", 34);
    else if (code == 2)
        write(2, "Some arguments not being integers\n", 34);
    else if (code == 3)
        write(2, "Some arguments exceeding the integer limits\n", 44);
    else if (code == 4)
        write(2, "Presence of duplicates\n", 23);
    return (code);
}

int main(int argc, char **argv)
{
    // t_list *a;
    // t_list *b;
    
    int     carg;

    if (argc == 2 || argc == 1)
        return (error(1));
    carg = check_args(argc, argv);
    if (carg)
        return (error(carg));
    ft_printf("Aucune erreur\n");
    return (0);
}