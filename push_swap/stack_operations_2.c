/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:02:48 by omawele           #+#    #+#             */
/*   Updated: 2026/01/10 14:53:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	ra(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	if (stkempty(*a) || stksize(*a) == 1)
		return (0);
	current = *a;
	next = current->next;
	*a = next;
	current->next = NULL;
	stkadd_back(a, current);
	rearrange_index(a);
	return (6);
}

int	rb(t_stack **b)
{
	t_stack	*current;
	t_stack	*next;

	if (stkempty(*b) || stksize(*b) == 1)
		return (0);
	current = *b;
	next = current->next;
	*b = next;
	current->next = NULL;
	stkadd_back(b, current);
	rearrange_index(b);
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
	current->prev = NULL;
	stkadd_front(a, current);
	rearrange_index(a);
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
	current->prev = NULL;
	stkadd_front(b, current);
	rearrange_index(b);
	return (10);
}
