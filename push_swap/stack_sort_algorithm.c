/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2026/01/08 10:57:22 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

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

static void sort_three_algorithm(t_stack **p, int (*sw)(t_stack **), int (*rev)(t_stack **), int (*rrev)(t_stack **))
{
    int fir;
    int sec;
    int thi;

    fir = (*p)->nb; 
    sec = (*p)->next->nb;
    thi = (*p)->next->next->nb;
    if (fir > sec && sec < thi && fir < thi)
        print_operations(sw(p));
    else if (fir < sec && sec > thi && fir > thi)
        print_operations(rrev(p));
    else if (fir > sec && sec < thi && fir > thi)
        print_operations(rev(p));
    else if (fir < sec && sec > thi && fir < sec)
    {
        print_operations(rrev(p));
        print_operations(sw(p));
    }
    else if (fir > sec && sec > thi && fir > thi)
    {
        print_operations(sw(p));
        print_operations(rrev(p));
    }
}

int sorting_check(t_stack **a, t_stack **b)
{
    t_stack *last;
    t_stack *beflast;
    int bigger;

    bigger = find_bigger_nb(*a);
    last = stklast(*a);
    beflast = stk_beflast(*a);
    if (last->nb > (*b)->nb)
    {
        if (beflast->nb < (*b)->nb || last->nb != bigger)
            return (1);
    }
    return (0);
}

void stack_sort_algorithm(t_stack **a, t_stack **b)
{
    t_check_operators o;
    
    if (stksize(*a) <= 3)
        return (sort_three_algorithm(a, &sa, &ra, &rra));
    print_operations(pb(a, b));
    print_operations(pb(a, b));
    while (stksize(*a) > 3)
    {
        calculate_step(*a, *b, &o);
        operator_exec(&o, a, b);
    }
    sort_three_algorithm(a, &sa, &ra, &rra);
    set_operator_check(&o);
    check_for_being_first_in_stack(&o, find_stk_pos(*b, find_bigger_nb(*b)), 'b', stksize(*b));
    operator_exec(&o, a, b);
    while (!stkempty(*b)) 
    {
        while (sorting_check(a, b))
            print_operations(rra(a));
        print_operations(pa(a, b));  
    }
    while (stklast(*a)->nb < (*a)->nb)
        print_operations(rra(a));
}


