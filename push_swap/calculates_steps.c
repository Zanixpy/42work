/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculates_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:29:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/09 17:35:44 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_a_costs(t_check_operators *o, t_stack *a, t_stack *p)
{
	int	size;
	int	nstk;

	size = stksize(a);
	nstk = find_stk_pos(a, p->nb);
	o->pos_stk = nstk;
	if (nstk > (size - 1) / 2)
		o->rra = size - nstk;
	else
		o->ra = nstk;
}

void	get_b_costs(t_check_operators *o, t_stack *b, t_stack *p)
{
	int	closest_smaller_nb;
	int	size_b;
	int	nstk;

	closest_smaller_nb = find_closest_smaller_nb(b, p->nb);
	size_b = stksize(b);
	if (find_smallest_nb(b) > p->nb)
		nstk = find_stk_pos(b, find_bigger_nb(b));
	else
		nstk = find_stk_pos(b, closest_smaller_nb);
	o->pos_stk = nstk;
	if (nstk > (size_b - 1) / 2)
		o->rrb = size_b - nstk;
	else
		o->rb = nstk;
}

int	total_steps(t_check_operators *o, t_stack *a, t_stack *b, t_stack *p)
{
	int	result;

	get_a_costs(o, a, p);
	get_b_costs(o, b, p);
	while (o->ra != 0 && o->rb != 0)
	{
		o->rr++;
		o->ra--;
		o->rb--;
	}
	while (o->rra != 0 && o->rrb != 0)
	{
		o->rrr++;
		o->rra--;
		o->rrb--;
	}
	while (o->sa != 0 && o->sb != 0)
	{
		o->ss++;
		o->sa--;
		o->sb--;
	}
	result = o->ra + o->rra + o->sa + o->rb + o->rrb + o->sb;
	return (result);
}

void	calculate_step(t_stack *a, t_stack *b, t_check_operators *o)
{
	t_check_operators	tmp;
	int					total;
	int					total_tmp;
	t_stack				*t;

	// int round;
	set_operator_check(o);
	set_operator_check(&tmp);
	t = a;
	total = 2147483646;
	// round = 0;
	// print_stack(a);
	while (t)
	{
		// ft_printf("ROund : %d\n", round);
		total_tmp = total_steps(&tmp, a, b, t);
		// ft_printf("Total_tmp : %d\n", total_tmp);
		if (total > total_tmp)
		{
			total = total_tmp;
			set_operator_check(o);
			*o = tmp;
		}
		// ft_printf("Total : %d\n", total);
		set_operator_check(&tmp);
		t = t->next;
		// round++;
	}
}
