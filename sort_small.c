/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:00:00 by acornia           #+#    #+#             */
/*   Updated: 2026/10/28 10:29:47 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x > y && y < z && x < z)
		sa(a);
	else if (x < y && y > z && x > z)
		rra(a);
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
}

static int	min_pos(t_node *stack)
{
	int	pos;
	int	best;
	int	min;

	pos = 0;
	best = 0;
	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			best = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (best);
}

static void	push_min(t_node **a, t_node **b)
{
	int	pos;
	int	size;

	pos = min_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	sort_small(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
		push_min(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
