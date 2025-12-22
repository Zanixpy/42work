/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:17 by omawele           #+#    #+#             */
/*   Updated: 2025/12/22 21:10:49 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_smallest_bigger_nb(t_stack *b, int *min, int *max)
{
    int tmin;
    int tmax;

    tmin = b->nb;
    tmax = b->nb;
    while (b)
    {
        if (tmin > b->nb)
            tmin = b->nb;
        if (tmax < b->nb)
            tmax = b->nb;
        b = b->next;
    }
    *min = tmin;
    *max = tmax;
}

int find_nearest_nb(t_stack *b, int nb)
{
    int nearest_nb;
    int diff;
    int tmp_diff;

    nearest_nb = 0;
    diff = INT_MAX;
    tmp_diff = 0;
    while (b)
    {
        if (nb > b->nb)
            tmp_diff = nb - b->nb;
        else
            tmp_diff = b->nb - nb;
        if (tmp_diff < diff)
        {
            diff = tmp_diff;
            nearest_nb = b->nb;
        }   
        b = b->next;
    }
    return (nearest_nb);
}

int check_steps_to_be_first(t_stack *p, t_stack *find)
{
    int steps;
    int size;
    int i;
    
    steps = 0;
    i = 0;
    size = stksize(p);
    while (size != 0)
    {
        /* code */
    }
    
    
}