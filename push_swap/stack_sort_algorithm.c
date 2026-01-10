/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:01:56 by omawele           #+#    #+#             */
/*   Updated: 2026/01/10 17:52:04 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	sort_three_algorithm(t_stack **a)
{
	int	fir;
	int	sec;
	int	thi;

	fir = (*a)->nbr;
	sec = (*a)->next->nbr;
	thi = (*a)->next->next->nbr;
	if (fir > sec && sec < thi && fir < thi)
		print_operations(sa(a));
	else if (fir < sec && sec > thi && fir > thi)
		print_operations(rra(a));
	else if (fir > sec && sec < thi && fir > thi)
		print_operations(ra(a));
	else if (fir < sec && sec > thi && fir < sec)
	{
		print_operations(rra(a));
		print_operations(sa(a));
	}
	else if (fir > sec && sec > thi && fir > thi)
	{
		print_operations(sa(a));
		print_operations(rra(a));
	}
}

void	execute_being_on_top(t_stack **a, t_stack **b)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = *a;
	current_b = *b;
	while (current_a) 
	{
		if (current_a->cheapest)
		{
			ft_printf("nb_a : %d, target : %d\n", current_a->nbr, current_a->target_node->nbr);
			being_on_top(a, current_a->index, 'a');
			break;
		}
		current_a = current_a->next;
	}
	while (current_b) 
	{
		if (current_a->target_node->nbr == current_b->nbr)
		{
			ft_printf("nb_a : %d\n", current_b->nbr);
			being_on_top(b, current_b->index, 'b');
			break;
		}
		current_b = current_b->next;
	}
}

void	sorting_check(t_stack **a, t_stack **b, int size)
{
	int	closest_bigger_nb;
	int	pos;
	int	mode;
	int	i;

	mode = 0;
	i = -1;
	if ((*b)->nbr > find_bigger_nb(*a))
		closest_bigger_nb = find_smallest_nb(*a);
	else
		closest_bigger_nb = find_closest_bigger_nb(*a, (*b)->nbr);
	pos = find_stk_pos(*a, closest_bigger_nb);
	if (pos > (size - 1) / 2)
	{
		pos = size - pos;
		mode = 1;
	}
	while (++i < pos)
	{
		if (mode)
			print_operations(rra(a));
		else
			print_operations(ra(a));
	}
	print_operations(pa(a, b));
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	// int					smallest;

	if (stksize(*a) == 4)
		print_operations(pb(a, b));
	else
	{
		print_operations(pb(a, b));
		print_operations(pb(a, b));
	}
	while (stksize(*a) > 3)
	{
		choose_cheapest(a, b);
		execute_being_on_top(a, b);
		print_operations(pb(a, b));
	}
	sort_three_algorithm(a);
	print_stack(*a);
	print_stack(*b);
}
