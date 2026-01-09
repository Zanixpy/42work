/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2026/01/09 18:27:20 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	set_operator_check(t_check_operators *o)
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

void	sort_three_algorithm(t_stack **a)
{
	int	fir;
	int	sec;
	int	thi;

	fir = (*a)->nb;
	sec = (*a)->next->nb;
	thi = (*a)->next->next->nb;
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

void	sorting_check(t_stack **a, t_stack **b, int size)
{
	int	closest_bigger_nb;
	int	pos;
	int	mode;
	int	i;

	mode = 0;
	i = -1;
	if ((*b)->nb > find_bigger_nb(*a))
		closest_bigger_nb = find_smallest_nb(*a);
	else
		closest_bigger_nb = find_closest_bigger_nb(*a, (*b)->nb);
	pos = find_stk_pos(*a, closest_bigger_nb);
	if (pos > (size - 1) / 2)
	{
		pos = size - pos;
		mode = 1;
	}
	while (++i < pos)
	{
		if (mode)
			print_operations(rra(a));
		else
			print_operations(rra(a));
	}
	print_operations(pa(a, b));
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	t_check_operators	o;
	int					smallest;

	if (stksize(*a) == 4)
		print_operations(pb(a, b));
	else
	{
		print_operations(pb(a, b));
		print_operations(pb(a, b));
	}
	while (stksize(*a) > 3)
	{
		calculate_step(*a, *b, &o);
		operator_exec(&o, a, b);
		print_operations((pb(a, b)));
	}
	sort_three_algorithm(a);
	while (stksize(*b) != 0)
		sorting_check(a, b, stksize(*a));
	smallest = find_smallest_nb(*a);
	while ((*a)->nb != smallest)
		print_operations(rra(a));
}
