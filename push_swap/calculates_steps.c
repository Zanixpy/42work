/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculates_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:29:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/08 10:31:29 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int calculate_total_steps(t_check_operators *o)
{
    while (o->ra != 0 && o->rb != 0) 
    {
        o->rr++;
        o->ra--;
        o->rb--;  
    }
    while (o->rra != 0 && o->rrb != 0) 
    {
        o->rrr++;
        o->rra--;
        o->rrb--;  
    }
    while (o->sa != 0 && o->sb != 0) 
    {
        o->ss++;
        o->sa--;
        o->sb--;  
    }
    return (o->ra + o->rb + o->rr + o->rra + o->rrb + o->rrr + \
        o->sa + o->sb + o->ss + o->pa + o->pb);
}

void check_for_being_first_in_stack(t_check_operators *o, int pos, char stk, int size_stk)
{
    o->pos_stk = pos;
    if (pos > (size_stk - 1) / 2)
    {
        if (stk == 'a')
            o->rra = size_stk - pos;
        else if (stk == 'b')
            o->rrb = size_stk - pos; 
    }
    else
    {
        if (stk == 'a')
            o->ra = pos;
        else if (stk == 'b')
            o->rb = pos;
    }
}

void check_for_b(t_check_operators *o, t_stack *p, t_stack *b)
{
    int nearest_nb;
    int check;
    int size_b;
    int nstk;

    nearest_nb = find_nearest_nb(b, p->nb);
    size_b = stksize(b);
    check = check_num_position(p, b);
    nstk = find_stk_pos(b, nearest_nb);
    o->pb += 1;
    if (check == 1 &&  nstk == size_b - 1)
        o->rb += 1;
    check_for_being_first_in_stack(o, nstk , 'b', size_b);
    if (check == 1 && nstk != size_b - 1)
        o->sb += 1;
}

int checking(t_stack *a, t_stack *b, t_stack *p, t_check_operators *o)
{
    check_for_being_first_in_stack(o, find_stk_pos(a, p->nb), 'a', stksize(a));
    check_for_b(o, a, b);
    return (calculate_total_steps(o)); 
}

void calculate_step(t_stack *a, t_stack *b, t_check_operators *o)
{
    t_check_operators tmp;
    int total;
    int total_tmp;
    t_stack *t;

    set_operator_check(o);
    set_operator_check(&tmp);
    total = checking(a, b, a, o);
    t = a->next;
    while (t) 
    {
        total_tmp = checking(a, b, t, &tmp);
        if (total > total_tmp)
        {
            total = total_tmp;
            set_operator_check(o);
            *o = tmp;
        }
        set_operator_check(&tmp);
        t = t->next;
    }
}
