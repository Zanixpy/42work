/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:07:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/04 21:46:57 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int stkempty(t_stack *p)
{
    if (stksize(p) == 0)
        return (1);
    return (0);  
}

int find_stk_pos(t_stack *p, int nb)
{
    int i;

    if (!p)
        return (-1);
    i = 0;
    while (p) 
    {
        if (p->nb == nb)
            return (i);
        p = p->next;
        i++;
    }
    return (- 1);
}

t_stack *find_stk(t_stack *p, int pos)
{
    int i;

    if (!p)
        return (NULL);
    i = 0;
    while (i <= pos) 
    {
        p = p->next;
        i++;
    }
    return (p);
}

void set_operator_check(t_check_operators *o)
{
    o->pa = 0;
    o->pb = 0;
    o->sa = 0;
    o->sb = 0;
    o->ss = 0;
    o->ra = 0;
    o->rb = 0;
    o->rr = 0;
    o->rra = 0;
    o->rrb = 0;
    o->rrr = 0;
    o->pos_stk = 0;
}