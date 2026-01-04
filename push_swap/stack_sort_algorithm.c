/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2026/01/04 22:51:31 by omawele          ###   ########.fr       */
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


void rearrange(t_stack **a, t_stack **b)
{
    int max;
    int first_nb_a;

    max = find_bigger_nb(*b);
    first_nb_a = (*a)->nb;
    while ((*b)->nb != max) 
    {
        print_operations(rb(b)); 
    }
    if (max > first_nb_a && max > (*a)->next->nb && (*a)->next->next->nb)
    {
        while (!stkempty(*b)) 
            print_operations(pa(a, b));    
    }
    ft_printf("%d \n", (*a)->nb);
}

void assemble(t_stack **a, t_stack **b)
{
    int first_nb_a;
    int check_switch;

    first_nb_a = (*a)->nb;
    check_switch = 0;
    if ((*b)->nb > first_nb_a)
    {
        check_switch = 1; 
        print_operations(ra(a));
    }
    while (!stkempty(*b)) 
    {
  
        if (check_switch && (*b)->nb < first_nb_a)
        {
            check_switch = 0;
            print_operations(rra(a));
        }
        print_operations(pa(a, b));    
    }
}

void stack_sort_algorithm(t_stack **a, t_stack **b, int stk_size)
{
    t_check_operators o;
    
    if (stk_size <= 3)
        return (sort_three_algorithm(a, &sa, &ra, &rra));
    print_operations(pb(a, b));
    print_operations(pb(a, b));
    while (stksize(*a) > 3)
    {
        calculate_step(*a, *b, &o);
        operator_exec(&o, a, b);
        // print_stack(*b);
        // ft_printf("\n");
        
    }
    sort_three_algorithm(a, &sa, &ra, &rra);
    print_stack(*a);
    rearrange(a, b);
    assemble(a, b);
}


