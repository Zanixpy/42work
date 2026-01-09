/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:41:02 by omawele           #+#    #+#             */
/*   Updated: 2026/01/09 16:36:14 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_operator_exec(t_check_operators *o, t_stack **a)
{
	while (o->ra != 0)
	{
		print_operations(ra(a));
		o->ra--;
	}
	while (o->rra != 0)
	{
		print_operations(rra(a));
		o->rra--;
	}
	while (o->sa != 0)
	{
		print_operations(sa(a));
		o->sa--;
	}
}

void	b_operator_exec(t_check_operators *o, t_stack **b)
{
	while (o->rb != 0)
	{
		print_operations(rb(b));
		o->rb--;
	}
	while (o->rrb != 0)
	{
		print_operations(rrb(b));
		o->rrb--;
	}
	while (o->sb != 0)
	{
		print_operations(sb(b));
		o->sb--;
	}
}

void	operator_exec(t_check_operators *o, t_stack **a, t_stack **b)
{
	while (o->rr != 0)
	{
		print_operations(rr(a, b));
		o->rr--;
	}
	while (o->rrr != 0)
	{
		print_operations(rrr(a, b));
		o->rrr--;
	}
	while (o->ss != 0)
	{
		print_operations(ss(a, b));
		o->ss--;
	}
	a_operator_exec(o, a);
	b_operator_exec(o, b);
}