/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculates_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:29:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/14 12:15:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_all_costs(t_stack **p)
{
	t_stack	*current;

	current = *p;
	while (current)
	{
		current->cheapest = 0;
		current->push_cost = 0;
		current->target_node = NULL;
		current->above_median = 0;
		current->a_push_cost = 0;
		current->b_push_cost = 0;
		current->operator_both = 0;
		current = current->next;
	}
}

void	assemble_costs(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		if ((current->above_median && current->target_node->above_median
				&& current->a_push_cost && current->b_push_cost)
			|| (!current->above_median && !current->target_node->above_median
				&& current->a_push_cost && current->b_push_cost))
		{
			while (current->a_push_cost && current->b_push_cost)
			{
				current->operator_both += 1;
				current->a_push_cost -= 1;
				current->b_push_cost -= 1;
			}
		}
		current->push_cost = current->operator_both + current->a_push_cost
			+ current->b_push_cost;
		current = current->next;
	}
}

void	get_all_costs(t_stack **a, t_stack **b)
{
	int	b_bigger_nb;
	int	b_smallest_nb;

	b_bigger_nb = find_bigger_nb(*b);
	b_smallest_nb = find_smallest_nb(*b);
	reset_all_costs(a);
	reset_all_costs(b);
	get_a_costs(a);
	get_b_costs(b, a, b_bigger_nb, b_smallest_nb);
	assemble_costs(a);
}

void	choose_cheapest(t_stack **a, t_stack **b)
{
	int		total;
	int		total_tmp;
	int		index_cheapest;
	t_stack	*t;

	t = *a;
	total = 2147483646;
	index_cheapest = 0;
	get_all_costs(a, b);
	while (t)
	{
		total_tmp = t->push_cost;
		if (total > total_tmp)
		{
			total = total_tmp;
			index_cheapest = t->index;
		}
		t = t->next;
	}
	if (total != 2147483646)
	{
		t = find_stk(*a, index_cheapest);
		if (t)
			t->cheapest = 1;
	}
}
