/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2025/12/21 20:10:30 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_three_algorithm(t_stack **p)
{
    int fir;
    int sec;
    int thi;

    fir = (*p)->nb; 
    sec = (*p)->next->nb;
    thi = (*p)->next->next->nb;
    if (fir > sec && sec < thi && fir < thi)
        print_operations(sa(p));
    else if (fir < sec && sec > thi && fir > thi)
        print_operations(rra(p));
    else if (fir > sec && sec < thi && fir > thi)
        print_operations(ra(p));
    else if (fir < sec && sec > thi && fir < sec)
    {
        print_operations(rra(p));
        print_operations(sa(p));
    }
    else if (fir > sec && sec > thi && fir > thi)
    {
        print_operations(sa(p));
        print_operations(rra(p));
    }
}

void stack_sort_algorithm(t_stack **a, t_stack **b, int stk_size)
{
    if (stk_size <= 3)
        return (sort_three_algorithm(a));
    print_operations(pb(a, b));
    print_operations(pb(a, b));    
}


