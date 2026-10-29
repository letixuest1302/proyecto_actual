/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:29:01 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 13:12:34 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "split/split.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/*Operaciones Swap*/
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
/*Operaciones Push*/
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
/*Operaciones Rotate*/
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
/*Operaciones Reverse Rotate*/
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
/*Gestion de errores*/
int		error(t_node *stack_a, char **split);
void	free_stack(t_node *stack);
void	free_split(char	**split);
/*Indice de desordenacion*/
float	disorder_index(t_node *stack);
int		is_sorted(t_node *stack);
/*Parseo*/
int		parse_args(int argc, char **argv, int start, t_node **stack);
void	assign_index(t_node *stack_a);
/*Comprobacion de argumentos*/
void	sort_stack(t_node **stack_a, t_node **stack_b, char *flag);
int		numbers(char *str);
long	ft_atol(const char *str);
int		duplicate(t_node *stack, int n);
int		add_back(t_node **stack, int n);
/*Algoritmos de ordenacion*/
void	simple_sort(t_node **stack_a, t_node **stack_b);
void	medium_sort(t_node **stack_a, t_node **stack_b);
void	complex_sort(t_node **stack_a, t_node **stack_b);

#endif