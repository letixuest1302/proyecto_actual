/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:52:15 by acornia           #+#    #+#             */
/*   Updated: 2026/11/06 12:45:51 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	reverserotate(t_node **stack)
{
	t_node	*last;
	t_node	*prev;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = *stack;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_node **stack_a, t_bench *bench)
{
	if (!reverserotate(stack_a))
		return ;
	write(1, "rra\n", 4);
	if (bench && bench->enabled)
	{
		bench->rra++;
		bench->total_ops++;
	}
}

void	rrb(t_node **stack_b, t_bench *bench)
{
	if (!reverserotate(stack_b))
		return ;
	write(1, "rrb\n", 4);
	if (bench && bench->enabled)
	{
		bench->rrb++;
		bench->total_ops++;
	}
}

void	rrr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	done_a;
	int	done_b;

	done_a = reverserotate(stack_a);
	done_b = reverserotate(stack_b);
	if (!done_a && !done_b)
		return ;
	write(1, "rrr\n", 4);
	if (bench && bench->enabled)
	{
		bench->rrr++;
		bench->total_ops++;
	}
}
