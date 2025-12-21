/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:47:58 by omawele           #+#    #+#             */
/*   Updated: 2025/12/21 16:25:05 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sa(t_stack **a)
{
    t_stack *current;
    t_stack *next;

    current = *a;
    if (stkempty(current) || stksize(current) == 1)
        return (0);
    next = current->next;
    current->next = next->next;
    next->next = current;
    *a = next;
    return (1); 
}

int sb(t_stack **b)
{
    t_stack *current;
    t_stack *next;

    current = *b;
    if (stkempty(current) || stksize(current) == 1)
        return (0);
    next = current->next;
    current->next = next->next;
    next->next = current;
    *b = next;
    return (2); 
}

int pa(t_stack **a, t_stack **b)
{
    t_stack *current;
    t_stack *next;

    current = *b;
    if (stkempty(current))
        return (0);
    next = current->next;
    *b = next;
    current->next = NULL;
    stkadd_front(a, current);
    return (4);
}

int pb(t_stack **a, t_stack **b)
{
    t_stack *current;
    t_stack *next;

    current = *a;
    if (stkempty(current))
        return (0);
    next = current->next;
    *a = next;
    current->next = NULL;
    stkadd_front(b, current);
    return (5);
}

