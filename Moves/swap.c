/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 10:52:24 by acornia           #+#    #+#             */
/*   Updated: 2026/11/06 12:45:43 by acornia & l      ###   ########.fr       */
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

void	sa(t_node **stack_a, t_bench *bench)
{
	if (!swap(stack_a))
		return ;
	write(1, "sa\n", 3);
	if (bench && bench->enabled)
	{
		bench->sa++;
		bench->total_ops++;
	}
}

void	sb(t_node **stack_b, t_bench *bench)
{
	if (!swap(stack_b))
		return ;
	write(1, "sb\n", 3);
	if (bench && bench->enabled)
	{
		bench->sb++;
		bench->total_ops++;
	}
}

void	ss(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	done_a;
	int	done_b;

	done_a = swap(stack_a);
	done_b = swap(stack_b);
	if (!done_a && !done_b)
		return ;
	write(1, "ss\n", 3);
	if (bench && bench->enabled)
	{
		bench->ss++;
		bench->total_ops++;
	}
}
