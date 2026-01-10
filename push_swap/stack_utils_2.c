/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:07:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/10 17:19:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_stk_pos(t_stack *p, int nb)
{
	if (!p)
		return (-1);
	while (p)
	{
		if (p->nbr == nb)
			return (p->index);
		p = p->next;
	}
	return (-1);
}

t_stack	*find_stk(t_stack *p, int index)
{
	int	i;

	if (!p)
		return (NULL);
	i = 0;
	while (i < index)
	{
		p = p->next;
		i++;
	}
	return (p);
}

void rearrange_index(t_stack **p)
{
	t_stack *tmp;
	int index;

	tmp = *p;
	index = 0;
	while (tmp) 
	{
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}
