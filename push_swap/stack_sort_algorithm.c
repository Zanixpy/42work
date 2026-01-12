/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2026/01/12 11:53:47 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	sort_three_algorithm(t_stack **a)
{
	int	fir;
	int	sec;
	int	thi;

	fir = (*a)->nbr;
	sec = (*a)->next->nbr;
	thi = (*a)->next->next->nbr;
	if (fir > sec && sec < thi && fir < thi)
		print_operations(sa(a));
	else if (fir < sec && sec > thi && fir > thi)
		print_operations(rra(a));
	else if (fir > sec && sec < thi && fir > thi)
		print_operations(ra(a));
	else if (fir < sec && sec > thi && fir < sec)
	{
		print_operations(rra(a));
		print_operations(sa(a));
	}
	else if (fir > sec && sec > thi && fir > thi)
	{
		print_operations(sa(a));
		print_operations(rra(a));
	}
}

void being_two_at_same_time(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->above_median && cheapest->target_node->above_median)
	{
		while ((*a)->nbr != cheapest->nbr && (*b)->nbr != cheapest->target_node->nbr)
			print_operations(rrr(a, b));		
	}
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
	{
		while ((*a)->nbr != cheapest->nbr && (*b)->nbr != cheapest->target_node->nbr)
			print_operations(rr(a, b));	
	}
}

void	execute_being_on_top(t_stack **a, t_stack **b)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = *a;
	current_b = *b;
	while (current_a) 
	{
		if (current_a->cheapest)
		{
			being_two_at_same_time(a, b, current_a);
			being_on_top(a, current_a->index, 'a');
			break;
		}
		current_a = current_a->next;
	}
	while (current_b) 
	{
		if (current_a->target_node->nbr == current_b->nbr)
		{
			being_on_top(b, current_b->index, 'b');
			break;
		}
		current_b = current_b->next;
	}
}

void	sorting_rest(t_stack **a, t_stack **b)
{
	int	size;
	int smallest;
	t_stack *target;

	while (stksize(*b)) 
	{
		size = stksize(*a);
		if ((*b)->nbr > find_bigger_nb(*a))
			target = find_stk(*a, find_stk_pos(*a, find_smallest_nb(*a)));
		else
		 	target = find_stk(*a, find_stk_pos(*a, find_closest_bigger_nb(*a, (*b)->nbr)));
		if (target && target->index > (size - 1) / 2)
			target->above_median = 1;
		else
			target->above_median = 0;
		being_on_top(a, target->index, 'a');
		print_operations(pa(a, b));
	}
	smallest = find_smallest_nb(*a);
	while ((*a)->nbr != smallest)
		print_operations(rra(a));
}

void	sort_algorithm(t_stack **a, t_stack **b)
{

	if (stksize(*a) == 4)
		print_operations(pb(a, b));
	else
	{
		print_operations(pb(a, b));
		print_operations(pb(a, b));
	}
	while (stksize(*a) > 3)
	{
		choose_cheapest(a, b);
		execute_being_on_top(a, b);
		print_operations(pb(a, b));
	}
	sort_three_algorithm(a);
	sorting_rest(a, b);
}
