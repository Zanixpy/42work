/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:53:03 by omawele           #+#    #+#             */
/*   Updated: 2025/12/17 21:44:20 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if ((argv[i][0] != '-') || (argv[i][j] < '0' || argv[i][j] > '9'))
		        return (1);
            j++;
        }
        if (j > 11)
            return (1);
        i++;
    }
    return (0);
}

int check_int_limit(int argc, char **argv)
{
    long n;
    int i;
    int j;

    i = 1;
    n = 0;
    while (i < argc)
    {
        j = 0;
        n = ft_atoi(argv[i][j]
        i++;
    }
    return (0);
}


int main(int argc, char **argv)
{
    t_list *stack;

    if (argc == 2)
        return (1);
        
    
    
    
    
}