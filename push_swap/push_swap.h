/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:50:03 by omawele           #+#    #+#             */
/*   Updated: 2026/01/10 17:28:14 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack_node
{
	int nbr;
	int index;
	int push_cost;
	int above_median;
	int cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
} t_stack;


// Handle errors

int	check_args(int argc, char **argv);
int	strcmp_int_limit(char *s, int mode);
int	ft_strcmp(const char *s1, const char *s2);

//  Stack initiation

t_stack	*init_a_stack_args(int argc, char **argv);

// Nodes initiation

t_stack	*stknew(int nb);
void	stkclear(t_stack **stk);
void	stkadd_front(t_stack **stk, t_stack *new);
void	stkadd_back(t_stack **stk, t_stack *new);
int	stksize(t_stack *stk);
t_stack	*stklast(t_stack *stk);
int	stkempty(t_stack *p);
int	find_stk_pos(t_stack *p, int nb);
t_stack	*find_stk(t_stack *p, int index);
void rearrange_index(t_stack **p);

// Stack utils

int	print_operations(int code);
void	print_stack(t_stack *p);


//  Commands

int					sa(t_stack **a);
int					sb(t_stack **b);
int					pa(t_stack **a, t_stack **b);
int					pb(t_stack **a, t_stack **b);
int					ra(t_stack **a);
int					rb(t_stack **b);
int					rra(t_stack **a);
int					rrb(t_stack **b);
int					ss(t_stack **a, t_stack **b);
int					rr(t_stack **a, t_stack **b);
int					rrr(t_stack **a, t_stack **b);

// Algorithms

void	sort_algorithm(t_stack **a, t_stack **b);
void	sort_three_algorithm(t_stack **a);
void	execute_being_on_top(t_stack **a, t_stack **b);
void being_on_top(t_stack **p, int index, char stk);
void	choose_cheapest(t_stack **a, t_stack **b);
int	find_closest_smaller_nb(t_stack *b, int nb);
int	find_closest_bigger_nb(t_stack *a, int nb);
int	find_bigger_nb(t_stack *p);
int	find_smallest_nb(t_stack *p);


#endif