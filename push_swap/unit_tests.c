/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:46:03 by omawele           #+#    #+#             */
/*   Updated: 2025/12/21 20:12:55 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **a, t_stack **b)
{
    ft_printf("Push a and b : ");
    pb(a, b);
    pb(a, b);
    pb(a, b);
    pa(a, b);
    if (stksize(*b) == 2)
        ft_printf("OK\n");
    else 
        ft_printf("KO\n");
}

void swap(t_stack **a, t_stack **b)
{
    int na;
    int nb;
    
    na = (*a)->nb;
    nb = (*b)->nb;
    ss(a, b);
    ft_printf("swap a and b : ");
    if ((*a)->nb != na && (*b)->nb != nb)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}

void rotate(t_stack **a, t_stack **b)
{
    int na;
    int nb;
    
    na = (*a)->nb;
    nb = (*b)->nb;
    rr(a, b);
    ft_printf("rotate a and b : ");
    if (stklast(*a)->nb == na && stklast(*b)->nb == nb)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}

void reverse_rotate(t_stack **a, t_stack **b)
{
    int na;
    int nb;
    
    na = stklast(*a)->nb;
    nb = stklast(*b)->nb;
    rrr(a, b);
    ft_printf("reverse rotate a and b : ");
    if ((*a)->nb == na && (*b)->nb == nb)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}

void print_stack(t_stack *p)
{
    int round = 0;
    
    while (p)
    {
        ft_printf("p[%d] : %d\n", round, p->nb);
        round++;
        p = p->next;
    }   
}

void unit_tests(t_stack **a, t_stack **b)
{
    push(a, b);
    swap(a, b);
    rotate(a, b);
    print_stack(*a);
    reverse_rotate(a,b);
    print_stack(*a);
}



