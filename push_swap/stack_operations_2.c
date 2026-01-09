/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:02:48 by omawele           #+#    #+#             */
/*   Updated: 2025/12/21 16:50:26 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	current = *a;
	if (stkempty(current) || stksize(current) == 1)
		return (0);
	next = current->next;
	*a = next;
	current->next = NULL;
	stkadd_back(a, current);
	return (6);
}

int	rb(t_stack **b)
{
	t_stack	*current;
	t_stack	*next;

	current = *b;
	if (stkempty(current) || stksize(current) == 1)
		return (0);
	next = current->next;
	*b = next;
	current->next = NULL;
	stkadd_back(b, current);
	return (7);
}
int	rra(t_stack **a)
{
	t_stack	*current;
	t_stack	*previous;
	t_stack	*next;

	if (stkempty(*a) || stksize(*a) == 1)
		return (0);
	current = *a;
	next = current->next;
	while (current)
	{
		if (!next)
		{
			previous->next = NULL;
			break ;
		}
		previous = current;
		current = next;
		next = next->next;
	}
	stkadd_front(a, current);
	return (9);
}

int	rrb(t_stack **b)
{
	t_stack	*current;
	t_stack	*previous;
	t_stack	*next;

	if (stkempty(*b) || stksize(*b) == 1)
		return (0);
	current = *b;
	next = current->next;
	while (current)
	{
		if (!next)
		{
			previous->next = NULL;
			break ;
		}
		previous = current;
		current = next;
		next = next->next;
	}
	stkadd_front(b, current);
	return (10);
}
