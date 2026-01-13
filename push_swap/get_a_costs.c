/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_costs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:06:05 by omawele           #+#    #+#             */
/*   Updated: 2026/01/13 22:54:18 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_a_costs(t_stack **a)
{
	t_stack *current;
    int size;

    current = *a;
	size = stksize(*a);
    while (current) 
    {
        if (current->index > (size - 1) / 2)
        {
            current->above_median = 1;
            current->a_push_cost = size - current->index;
        }
        else 
        {
            current->above_median = 0;
            current->a_push_cost = current->index;
        }
        current = current->next;
    }
}
