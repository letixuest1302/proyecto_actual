/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:00:00 by acornia           #+#    #+#             */
/*   Updated: 2026/10/28 10:29:35 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "split.h"

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node	*next;
}	t_node;

/* error.c */
void	free_stack(t_node **stack);
void	free_split(char **split);
int	error(t_node **stack_a, char **split);

/* parse.c */
int	numbers(char *str);
int	duplicate(t_node *stack, int n);
int	add_back(t_node **stack, int n);
void	assign_index(t_node *stack_a);
long	ft_atol(const char *str);

/* parse_args.c */
int	parse_args(int argc, char **argv, t_node **stack);

/* operations */
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

/* sorting */
int	stack_size(t_node *stack);
int	is_sorted(t_node *stack);
void	sort_three(t_node **a);
void	sort_small(t_node **a, t_node **b);
void	push_swap(t_node **a, t_node **b);

#endif
