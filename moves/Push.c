/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:13:28 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 13:12:33 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;

	if (!stack_a || !stack_b)
		return ;
	node_to_move = *stack_b;
	*stack_b = (*stack_b)->next;
	node_to_move->next = *stack_a;
	*stack_a = node_to_move;
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node_to_move;

	node_to_move = *stack_a;
	*stack_a = (*stack_a)->next;
	node_to_move->next = *stack_b;
	*stack_b = node_to_move;
	write(1, "pb\n", 3);
}
