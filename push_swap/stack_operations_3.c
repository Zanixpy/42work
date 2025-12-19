/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:27:13 by omawele           #+#    #+#             */
/*   Updated: 2025/12/19 17:29:09 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ss(t_stack **a, t_stack **b)
{
    if (!stkempty(*a) || !stkempty(*b) \
        || stksize(*a) == 1 || stksize(*b) == 1)
        return (0);
    sa(a);
    sb(b);
    return (3);
}

int rr(t_stack **a, t_stack **b)
{
    if (!stkempty(*a) || !stkempty(*b) \
        || stksize(*a) == 1 || stksize(*b) == 1)
        return (0);
    ra(a);
    rb(b);
    return (8);
}

int rrr(t_stack **a, t_stack **b)
{
    if (!stkempty(*a) || !stkempty(*b) \
        || stksize(*a) == 1 || stksize(*b) == 1)
        return (0);
    rra(a);
    rrb(b);
    return (11);
}
