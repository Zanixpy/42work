/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:02:48 by omawele           #+#    #+#             */
/*   Updated: 2025/12/19 17:51:53 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ra(t_stack **a)
{
    t_stack *current;
    t_stack *next;

    current = *a;
    if (!stkempty(current) || stksize(current) == 1)
        return (0);
    next = current->next;
    *a = next;
    current->next = NULL;
    stkadd_back(a, current);
    return (6);
}

int rb(t_stack **b)
{
    t_stack *current;
    t_stack *next;

    current = *b;
    if (!stkempty(current) || stksize(current) == 1)
        return (0);
    next = current->next;
    *b = next;
    current->next = NULL;
    stkadd_back(b, current);
    return (7);
}
int rra(t_stack **a)
{
    t_stack *current;
    t_stack *before_last;
    t_stack *last;

    current = *a;
    if (!stkempty(current) || stksize(current) == 1)
        return (0);
    last = stklast(current);
    stkadd_front(a, last);
    before_last = stkbeflast(current);
    while (current->next != NULL)
    {
        if (current->nb == before_last->nb)
        {
            current->next = NULL;
            break;            
        }
        current = current->next;
    }
    return (9);
}

int rrb(t_stack **b)
{
    t_stack *current;
    t_stack *before_last;
    t_stack *last;

    current = *b;
    if (!stkempty(current) || stksize(current) == 1)
        return (0);
    last = stklast(current);
    stkadd_front(b, last);
    before_last = stkbeflast(current);
    while (current->next != NULL)
    {
        if (current->nb == before_last->nb)
        {
            current->next = NULL;
            break;            
        }
        current = current->next;
    }
    return (10);
}



