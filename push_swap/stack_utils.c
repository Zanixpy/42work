/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:09:48 by omawele           #+#    #+#             */
/*   Updated: 2026/01/13 18:09:38 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

void	stkadd_front(t_stack **stk, t_stack *new)
{
	t_stack	*p;

	p = *stk;
	if (p == NULL)
	{
		*stk = new;
		return ;
	}
	new->prev = NULL;
	new->next = p;
	*stk = new;
}

void	stkadd_back(t_stack **stk, t_stack *new)
{
	t_stack	*p;

	p = *stk;
	if (p == NULL)
	{
		*stk = new;
		return ;
	}
	while (p != NULL)
	{
		if (p->next == NULL)
		{
			new->prev = p;
			p->next = new;
			return ;
		}
		p = p->next;
	}
}

int	stksize(t_stack *stk)
{
	int	n;

	if (!stk)
		return (0);
	n = 0;
	while (stk)
	{
		n++;
		stk = stk->next;
	}
	return (n);
}

t_stack	*stklast(t_stack *stk)
{
	if (!stk)
		return (NULL);
	while (stk)
	{
		if (stk->next == NULL)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

void rearrange_index(t_stack **p)
{
	t_stack *tmp;
	int index;

	if (!p || !(*p))
		return;
	tmp = *p;
	index = 0;
	while (tmp) 
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}
