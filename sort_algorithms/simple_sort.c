/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:43:55 by lesainz           #+#    #+#             */
/*   Updated: 2026/11/03 15:48:19 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	min_to_top(t_node **stack_a, t_bench *bench)
{
	int	pos;
	int	size;

	pos = index_min_pos(*stack_a);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack_a, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(stack_a, bench);
			pos++;
		}
	}
}

void	simple_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
	{
		sa(stack_a, bench);
		return ;
	}
	while (size > 3)
	{
		min_to_top(stack_a, bench);
		pb(stack_a, stack_b, bench);
		size--;
	}
	sort_three(stack_a, bench);
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}

void	sort_three(t_node **stack_a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack_a, bench);
	else if (first > second && second > third)
	{
		sa(stack_a, bench);
		rra(stack_a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, bench);
		ra(stack_a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, bench);
}
