/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2026/01/14 15:27:47 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	execute_being_on_top(t_stack **a, t_stack **b)
{
	t_stack	*current_a;

	current_a = *a;
	while (current_a)
	{
		if (current_a->cheapest)
			break ;
		current_a = current_a->next;
	}
	if (current_a->operator_both && current_a->above_median
		&& current_a->target_node->above_median)
	{
		while (current_a->operator_both > 0 && current_a->operator_both--)
			print_operations(rrr(a, b));
	}
	else if (current_a->operator_both && !current_a->above_median
		&& !current_a->target_node->above_median)
	{
		while (current_a->operator_both > 0 && current_a->operator_both--)
			print_operations(rr(a, b));
	}
	if (current_a->a_push_cost > 0)
		being_on_top(a, current_a->index, 'a');
	if (current_a->b_push_cost > 0)
		being_on_top(b, current_a->target_node->index, 'b');
}

void	sorting_rest(t_stack **a, t_stack **b)
{
	int		size;
	int		smallest;
	t_stack	*target;

	while (stksize(*b))
	{
		size = stksize(*a);
		if ((*b)->nbr > find_bigger_nb(*a))
			target = find_stk(*a, find_index(*a, find_smallest_nb(*a)));
		else
			target = find_stk(*a, find_index(*a, find_cb_nb(*a, (*b)->nbr)));
		if (target)
		{
			if (target->index > (size - 1) / 2)
				target->above_median = 1;
			else
				target->above_median = 0;
			being_on_top(a, target->index, 'a');
		}
		print_operations(pa(a, b));
	}
	smallest = find_smallest_nb(*a);
	while ((*a)->nbr != smallest)
		print_operations(rra(a));
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	b_bigger_nb;

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
	b_bigger_nb = find_bigger_nb(*b);
	being_on_top(b, find_index(*b, b_bigger_nb), 'b');
	sorting_rest(a, b);
}
