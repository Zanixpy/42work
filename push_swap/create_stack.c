/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 21:07:27 by omawele           #+#    #+#             */
/*   Updated: 2026/01/14 12:15:33 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stknew(int nb)
{
	t_stack	*p;

	p = malloc(sizeof(t_stack));
	if (p == NULL)
		return (NULL);
	p->nbr = nb;
	p->next = NULL;
	p->prev = NULL;
	p->target_node = NULL;
	p->above_median = 0;
	p->cheapest = 0;
	p->push_cost = 0;
	return (p);
}

void	stkclear(t_stack **stk)
{
	t_stack	*current;
	t_stack	*next;

	if (!stk || !(*stk))
		return ;
	current = *stk;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stk = NULL;
}

t_stack	*init_a_stack_args(int argc, char **argv)
{
	t_stack	*p;
	t_stack	*tmp;
	int		i;
	int		nb;

	i = 2;
	nb = ft_atoi(argv[1]);
	p = stknew(nb);
	if (!p)
		return (NULL);
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		tmp = stknew(nb);
		if (!tmp)
			return (stkclear(&p), NULL);
		stkadd_back(&p, tmp);
		i++;
	}
	rearrange_index(&p);
	return (p);
}
