/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:47:58 by omawele           #+#    #+#             */
/*   Updated: 2026/01/12 11:25:09 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	sa(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;
	t_stack *next_next;

	if (!(*a) || !a|| stksize(*a) == 1)
		return (0);
	current = *a;
	next = current->next;
	next_next = next->next;
	next_next->prev = current;
	current->next = next_next;
	current->prev = next;
	next->next = current;
	next->prev = NULL;
	*a = next;
	rearrange_index(a);
	return (1);
}

int	sb(t_stack **b)
{
	t_stack	*current;
	t_stack	*next;
	t_stack *next_next;

	if (!(*b) || !b || stksize(*b) == 1)
		return (0);
	current = *b;
	next = current->next;
	next_next = next->next;
	next_next->prev = current;
	current->next = next_next;
	current->prev = next;
	next->next = current;
	next->prev = NULL;
	*b = next;
	rearrange_index(b);
	return (2);
}

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*next;

	if (!(*b) || !b)
		return (0);
	current = *b;
	if (current->next)
	{
		next = current->next;
		next->prev = NULL;
		*b = next;
		current->next = NULL;
	} 
	else
		*b = NULL; 
	stkadd_front(a, current);
	rearrange_index(a);
	rearrange_index(b);
	return (4);
}

int	pb(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*next;

	if (!(*a) || !a)
		return (0);
	current = *a; 
	if (current->next)
	{
		next = current->next;
		next->prev = NULL;
		*a = next;
		current->next = NULL;
	} 
	else
		*a = NULL; 
	stkadd_front(b, current);
	rearrange_index(a);
	rearrange_index(b);
	return (5);
}
