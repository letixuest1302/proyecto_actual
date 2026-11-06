/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 12:30:52 by acornia & l       #+#    #+#             */
/*   Updated: 2026/11/06 12:45:47 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_node **stack_a, t_bench *bench)
{
	if (!rotate(stack_a))
		return ;
	write(1, "ra\n", 3);
	if (bench && bench->enabled)
	{
		bench->ra++;
		bench->total_ops++;
	}
}

void	rb(t_node **stack_b, t_bench *bench)
{
	if (!rotate(stack_b))
		return ;
	write(1, "rb\n", 3);
	if (bench && bench->enabled)
	{
		bench->rb++;
		bench->total_ops++;
	}
}

void	rr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	done_a;
	int	done_b;

	done_a = rotate(stack_a);
	done_b = rotate(stack_b);
	if (!done_a && !done_b)
		return ;
	write(1, "rr\n", 3);
	if (bench && bench->enabled)
	{
		bench->rr++;
		bench->total_ops++;
	}
}
