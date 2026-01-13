/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:07:29 by omawele           #+#    #+#             */
/*   Updated: 2026/01/13 23:21:06 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	get_b_costs(t_stack **b, t_stack **a, int b_bigger_nb, int b_smallest_nb)
{
    t_stack *current;
    t_stack *target_node;
    int bsize;

    current = *a;
    bsize = stksize(*b);
    while (current) 
    {
        if (current->nbr < b_smallest_nb)
            target_node = find_stk(*b, find_stk_pos(*b, b_bigger_nb));
        else
            target_node = find_stk(*b, find_stk_pos(*b, find_closest_smaller_nb(*b, current->nbr)));
        if (target_node && target_node->index > (bsize - 1) / 2)
        {
            target_node->above_median = 1;
            current->b_push_cost = bsize - target_node->index;
        }
        else if (target_node)
        {
            target_node->above_median = 0;
            current->b_push_cost = target_node->index;
        }
        current->target_node = target_node;
        current = current->next;
    }
}
