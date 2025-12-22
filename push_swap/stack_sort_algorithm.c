/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2025/12/22 21:00:25 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void calculate_cheapest_step(t_stack **a, t_stack **b, int *min_b, int *max_b)
{
    
}

// void put_nb_first_in_a(t_stack **a, t_stack **b)
// {
//     ;
// }

// void put_nb to the_nearest()


void stack_sort_algorithm(t_stack **a, t_stack **b, int stk_size)
{
    int min_b;
    int max_b;

    if (stk_size <= 3)
        return (sort_three_algorithm(a, &sa, &ra, &rra));
    print_operations(pb(a, b));
    print_operations(pb(a, b));
    find_smallest_bigger_nb(*b, &min_b, &max_b);
    while (!stkempty(*b))
    {
        /* code */
    }
    
    find_nearest_nb(*b, 13);   
}


