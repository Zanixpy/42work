/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2025/12/21 18:22:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_algorithm(t_stack **p, int mode)
{
    t_stack *current;
    t_stack *next;

    next = (*p)->next;
    while (next)
    {
        if ((*p)->nb > next->nb && mode)
            print_operations(sa(p));
        else if ((*p)->nb > next->nb && !mode)
            print_operations(sb(p));
        else if ((*p)->nb > next->nb && mode)
            print_operations(ra(p));
        else if ((*p)->nb > next->nb && !mode)
            print_operations(rb(p));
        next = next->next; 
    }
}
void stack_sort_algorithm(t_stack **a, t_stack **b, int stk_size)
{
    if (stk_size <= 3)
        return (sort_three_algorithm(a, 1));
    print_operations(pb(a, b));
    print_operations(pb(a, b));    
}


