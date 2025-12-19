/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:50:03 by omawele           #+#    #+#             */
/*   Updated: 2025/12/19 17:57:59 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int			nb;
}					t_stack;

int strcmp_int_limit(char *s, int mode);
int check_args(int argc, char **argv);
int	ft_strcmp(const char *s1, const char *s2);
t_stack  *init_a_stack(int argc, char **argv);
void	stkadd_front(t_stack **stk, t_stack *new);
void	stkadd_back(t_stack **stk, t_stack *new);
void	stkclear(t_stack **stk);
int	stksize(t_stack *stk);
t_stack	*stklast(t_stack *stk);
int stkempty(t_stack *p);
t_stack	*stkbeflast(t_stack *stk);
int sa(t_stack **a);
int sb(t_stack **b);
int pa(t_stack **a, t_stack **b);
int pb(t_stack **a, t_stack **b);
int ra(t_stack **a);
int rb(t_stack **b);
int rra(t_stack **a);
int rrb(t_stack **b);
int ss(t_stack **a, t_stack **b);
int rr(t_stack **a, t_stack **b);
int rrr(t_stack **a, t_stack **b);

#endif