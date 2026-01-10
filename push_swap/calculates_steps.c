/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculates_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:29:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/10 17:44:52 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void reset_all_costs(t_stack **a, t_stack **b)
{
	t_stack *current;

	current = *a;
	while (current) 
	{
		current->cheapest = 0;
		current->push_cost = 0;
		current->target_node = NULL;
		current->above_median = 0;
		current = current->next;	
	}
	current = *b;
	while (current) 
	{
		current->cheapest = 0;
		current->push_cost = 0;
		current->target_node = NULL;
		current->above_median = 0;
		current = current->next;	
	}
}

void	get_a_costs(t_stack **a, t_stack *p)
{
	int	size;

	size = stksize(*a);
	if (p->index > (size - 1) / 2)
	{
		p->above_median = 1;
		p->push_cost += size - p->index;
		return;
	}
	p->above_median = 0;
	p->push_cost += p->above_median;
}

void	get_b_costs(t_stack **b, t_stack *p)
{
	int	closest_smaller_nb;
	int	size;
	t_stack *target;

	closest_smaller_nb = find_closest_smaller_nb(*b, p->nbr);
	size = stksize(*b);
	if (find_smallest_nb(*b) > p->nbr)
		target = find_stk(*b, find_stk_pos(*b, find_bigger_nb(*b)));
	else
		target = find_stk(*b, find_stk_pos(*b, closest_smaller_nb));
	if (target && target->index > (size - 1) / 2)
	{
		target->above_median = 1;
		target->push_cost += size - target->index;
	}
	else if (target)
	{
		target->above_median = 0;
		target->push_cost += target->index;
	}
	p->target_node = target;
}

void	get_all_costs(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp) 
	{
		get_a_costs(a, tmp);
		get_b_costs(b, tmp);
		// ft_printf("first a cost : %d et target node nb : %d\n", )
		tmp = tmp->next;
	}
}

void	choose_cheapest(t_stack **a, t_stack **b)
{
	int					total;
	int					total_tmp;
	int 	index_cheapest;
	t_stack				*t;

	t = *a;
	total = 2147483646;
	reset_all_costs(a, b);
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
	t = find_stk(*a, index_cheapest);
	t->cheapest = 1;
}
