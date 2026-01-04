/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/04 20:44:25 by omawele          ###   ########.fr       */
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

int check_num_position(t_stack *p, t_stack *b)
{
    int nearest_nb;
    
    nearest_nb = find_nearest_nb(b, p->nb);
    if (p->nb < nearest_nb)
        return (1);
    return (0);        
}

void a_operator_exec(t_check_operators *o, t_stack **a, t_stack **b)
{
    while (o->pa != 0) 
    {
        print_operations(pa(a, b));
        o->pa--;
    }  
    while (o->ra != 0) 
    {
        print_operations(ra(a));
        o->ra--;
    }
    while (o->rra != 0) 
    {
        print_operations(rra(a));
        o->rra--;
    }
    while (o->sa != 0) 
    {
        print_operations(sa(a));
        o->sa--;
    }
}

void b_operator_exec(t_check_operators *o, t_stack **a, t_stack **b)
{
    while (o->rb != 0) 
    {
        print_operations(rb(b));
        o->rb--;
    }
    while (o->rrb != 0) 
    {
        print_operations(rrb(b));
        o->rrb--;
    }
    while (o->pb != 0) 
    {
        print_operations(pb(a, b));
        o->pb--;
    } 
    while (o->sb != 0) 
    {
        print_operations(sb(b));
        o->sb--;
    }
}

void operator_exec(t_check_operators *o, t_stack **a, t_stack **b)
{
    while (o->rrr != 0) 
    {
        print_operations(rrr(a, b));
        o->rrr--; 
    }
    while (o->rr != 0) 
    {
        print_operations(rr(a, b));
        o->rr--; 
    }
    while (o->ss != 0) 
    {
        print_operations(ss(a, b));
        o->ss--; 
    }
    a_operator_exec(o, a, b);
    b_operator_exec(o, a, b);
}



