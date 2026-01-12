/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:07:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/12 11:21:13 by omawele          ###   ########.fr       */
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


