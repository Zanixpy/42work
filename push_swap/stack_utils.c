/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:09:48 by omawele           #+#    #+#             */
/*   Updated: 2025/12/20 18:00:26 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stkadd_front(t_stack **stk, t_stack *new)
{
	t_stack	*p;

	p = *stk;
	if (p == NULL)
	{
		*stk = new;
		return ;
	}
	*stk = new;
	new->next = p;
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
			p->next = new;
			return ;
		}
		p = p->next;
	}
}
void	stkdelone(t_list *stk)
{
	if (!stk)
		return ;
	free(stk);
}

int	stksize(t_stack *stk)
{
	int		n;

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
