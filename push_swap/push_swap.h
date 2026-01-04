/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:50:03 by omawele           #+#    #+#             */
/*   Updated: 2026/01/04 21:50:27 by omawele          ###   ########.fr       */
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

typedef struct s_check_operators
{
	int pos_stk;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
}					t_check_operators;

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
void unit_tests(t_stack **a, t_stack **b);
int print_operations(int code);
int is_sorted(t_stack *a);
void stack_sort_algorithm(t_stack **a, t_stack **b, int stk_size);
void find_smallest_bigger_nb(t_stack *b, int *min, int *max);
int find_nearest_nb(t_stack *b, int nb);
int find_stk_pos(t_stack *p, int nb);
t_stack *find_stk(t_stack *p, int pos);
void put_nb_first_stack(t_stack **p, int pos, int (*rev)(t_stack **), int (*rrev)(t_stack **));
int check_num_position(t_stack *p, t_stack *b);
void set_operator_check(t_check_operators *o);
void calculate_step(t_stack *a, t_stack *b, t_check_operators *o);
void a_operator_exec(t_check_operators *o, t_stack **a, t_stack **b);
void b_operator_exec(t_check_operators *o, t_stack **a, t_stack **b);
void operator_exec(t_check_operators *o, t_stack **a, t_stack **b);
int find_bigger_nb(t_stack *p);
void print_stack(t_stack *p);

#endif