/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:17 by omawele           #+#    #+#             */
/*   Updated: 2026/01/09 15:27:40 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_closest_smaller_nb(t_stack *b, int nb)
{
	int	nearest_nb;
	int	diff;
	int	tmp_diff;

	nearest_nb = 0;
	diff = INT_MAX;
	tmp_diff = 0;
	while (b)
	{
		if (b->nb < nb)
			tmp_diff = nb - b->nb;
		if (tmp_diff < diff && b->nb < nb)
		{
			diff = tmp_diff;
			nearest_nb = b->nb;
		}
		b = b->next;
	}
	return (nearest_nb);
}

int	find_closest_bigger_nb(t_stack *a, int nb)
{
	int	nearest_nb;
	int	diff;
	int	tmp_diff;

	nearest_nb = 0;
	diff = INT_MAX;
	tmp_diff = 0;
	while (a)
	{
		if (a->nb > nb)
			tmp_diff = a->nb - nb;
		if (tmp_diff < diff && a->nb > nb)
		{
			diff = tmp_diff;
			nearest_nb = a->nb;
		}
		a = a->next;
	}
	return (nearest_nb);
}

int	find_bigger_nb(t_stack *p)
{
	int	max;

	max = p->nb;
	while (p)
	{
		if (max < p->nb)
			max = p->nb;
		p = p->next;
	}
	return (max);
}

int	find_smallest_nb(t_stack *p)
{
	int	min;

	min = p->nb;
	while (p)
	{
		if (min > p->nb)
			min = p->nb;
		p = p->next;
	}
	return (min);
}
