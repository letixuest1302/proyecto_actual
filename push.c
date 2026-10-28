/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:00:00 by acornia           #+#    #+#             */
/*   Updated: 2026/10/28 10:29:38 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;

	if (!*stack_b)
		return ;
	node_to_move = *stack_b;
	*stack_b = node_to_move->next;
	node_to_move->next = *stack_a;
	*stack_a = node_to_move;
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;

	if (!*stack_a)
		return ;
	node_to_move = *stack_a;
	*stack_a = node_to_move->next;
	node_to_move->next = *stack_b;
	*stack_b = node_to_move;
	write(1, "pb\n", 3);
}
