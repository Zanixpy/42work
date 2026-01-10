/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:53:03 by omawele           #+#    #+#             */
/*   Updated: 2026/01/10 16:42:54 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	error(int code)
{
	write(2, "Error\n", 6);
	if (code == 1)
		write(2, "No arguments or only one argument\n", 34);
	else if (code == 2)
		write(2, "Some arguments not being integers\n", 34);
	else if (code == 3)
		write(2, "Some arguments exceeding the integer limits\n", 44);
	else if (code == 4)
		write(2, "Presence of duplicates\n", 23);
	else if (code == 5)
		write(2, "Problem with the creation of stack a\n", 37);
	return (code);
}

int	print_operations(int code)
{
	if (code == 1)
		ft_printf("sa\n");
	else if (code == 2)
		ft_printf("sb\n");
	else if (code == 3)
		ft_printf("ss\n");
	else if (code == 4)
		ft_printf("pa\n");
	else if (code == 5)
		ft_printf("pb\n");
	else if (code == 6)
		ft_printf("ra\n");
	else if (code == 7)
		ft_printf("rb\n");
	else if (code == 8)
		ft_printf("rr\n");
	else if (code == 9)
		ft_printf("rra\n");
	else if (code == 10)
		ft_printf("rrb\n");
	else if (code == 11)
		ft_printf("rrr\n");
	return (code);
}
void	print_stack(t_stack *p)
{
	while (p)
	{
		ft_printf("p[%d] : %d\n", p->index, p->nbr);
		p = p->next;
	}
}
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		carg;
	int		stk_size;

	if (argc == 2 || argc == 1)
		return (error(1));
	carg = check_args(argc, argv);
	if (carg)
		return (error(carg));
	b = NULL;
	a = init_a_stack_args(argc, argv);
	if (!a)
		return (5);
	stk_size = stksize(a);
	if (stk_size <= 3)
		sort_three_algorithm(&a);
	else
		sort_algorithm(&a, &b);
	// ft_printf("a :\n");
	// print_stack(a);
	stkclear(&a);
	return (0);
}
