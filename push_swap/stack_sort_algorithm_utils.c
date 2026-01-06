/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/06 13:34:26 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        if (b->nb < nb)
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

int check_num_position(t_stack *p, t_stack *b)
{
    int nearest_nb;
    
    nearest_nb = find_nearest_nb(b, p->nb);
    if (p->nb < nearest_nb)
        return (1);
    return (0);        
}

int find_bigger_nb(t_stack *p)
{
    int max;

    max = p->nb;
    while (p)
    {
        if (max < p->nb)
            max = p->nb;
        p = p->next;
    }
    return (max);
}

int find_smallest_nb(t_stack *p)
{
    int max;

    max = p->nb;
    while (p)
    {
        if (max < p->nb)
            max = p->nb;
        p = p->next;
    }
    return (max);
}







