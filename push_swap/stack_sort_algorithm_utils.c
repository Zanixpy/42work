/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/13 23:28:37 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_smaller_nb(t_stack *b, int nb)
{
	int	nearest_nb;
	int	diff;
	int	tmp_diff;

	nearest_nb = 0;
	diff = INT_MAX;
	tmp_diff = 0;
	while (b)
	{
		if (b->nbr < nb)
			tmp_diff = nb - b->nbr;
		if (tmp_diff < diff && b->nbr < nb)
		{
			diff = tmp_diff;
			nearest_nb = b->nbr;
		}
		b = b->next;
	}
	return (nearest_nb);
}

int	find_closest_bigger_nb(t_stack *a, int nb)
{
	int	nearest_nb;
	int	diff;
	int	tmp_diff;

	nearest_nb = 0;
	diff = INT_MAX;
	tmp_diff = 0;
	while (a)
	{
		if (a->nbr > nb)
			tmp_diff = a->nbr - nb;
		if (tmp_diff < diff && a->nbr > nb)
		{
			diff = tmp_diff;
			nearest_nb = a->nbr;
		}
		a = a->next;
	}
	return (nearest_nb);
}

int	find_bigger_nb(t_stack *p)
{
	int	max;

	max = p->nbr;
	while (p)
	{
		if (max < p->nbr)
			max = p->nbr;
		p = p->next;
	}
	return (max);
}

int	find_smallest_nb(t_stack *p)
{
	int	min;

	min = p->nbr;
	while (p)
	{
		if (min > p->nbr)
			min = p->nbr;
		p = p->next;
	}
	return (min);
}

void being_on_top(t_stack **p, int index, char stk)
{
	t_stack *tmp;

	tmp = find_stk(*p, index);
	if (tmp->index > (stksize(*p) - 1) / 2)
		tmp->above_median = 1;
	else
		tmp->above_median = 0;
	if (tmp->above_median)
	{
		if (stk == 'a')
		{
			while ((*p)->nbr != tmp->nbr)
				print_operations(rra(p));
		}
		while ((*p)->nbr != tmp->nbr)
			print_operations(rrb(p));
		return;
	}
	if (stk == 'a')
	{
		while ((*p)->nbr != tmp->nbr)
			print_operations(ra(p));
	}
	while ((*p)->nbr != tmp->nbr)
		print_operations(rb(p));
}
