/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:52:15 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 16:08:22 by acornia          ###   ########.fr       */
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

void	rra(t_node **stack_a)
{
	if (reverserotate(stack_a))
		write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	if (reverserotate(stack_b))
		write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	int	done_a;
	int	done_b;

	done_a = reverserotate(stack_a);
	done_b = reverserotate(stack_b);
	if (done_a && done_b)
		write(1, "rrr\n", 4);
	else if (done_a)
		write(1, "rra\n", 4);
	else if (done_b)
		write(1, "rrb\n", 4);
}
