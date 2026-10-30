/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 10:52:24 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 16:07:07 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_node **stack)
{
	int	tmp_value;
	int	tmp_index;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp_value = (*stack)->value;
	tmp_index = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = tmp_value;
	(*stack)->next->index = tmp_index;
	return (1);
}

void	sa(t_node **stack_a)
{
	if (swap(stack_a))
		write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	if (swap(stack_b))
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	int	done_a;
	int	done_b;
	
	done_a = swap(stack_a);
	done_b = swap(stack_b);
	if (done_a && done_b)
		write(1, "ss\n", 3);
	else if (done_a)
		write(1, "sa\n", 3);
	else if (done_b)
		write(1, "sb\n", 3);
}
