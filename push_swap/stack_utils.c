/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:09:48 by omawele           #+#    #+#             */
/*   Updated: 2026/01/10 16:37:33 by omawele          ###   ########.fr       */
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
	while (stk != NULL)
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
	while (stk != NULL)
	{
		if (stk->next == NULL)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

int	stkempty(t_stack *p)
{
	if (stksize(p) == 0)
		return (1);
	return (0);
}
