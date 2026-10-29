/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:43:55 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/29 13:12:33 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **stack_a);

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static int	index_min_pos(t_node *stack)
{
	int	min_idx;
	int	min_pos;
	int	current_pos;

	min_idx = stack->index;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->index < min_idx)
		{
			min_idx = stack->index;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

static void	min_to_top(t_node **stack_a)
{
	int	pos;
	int	size;

	pos = index_min_pos(*stack_a);
	size = stack_size(*stack_a);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(stack_a);
			pos++;
		}
	}
}

void	simple_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	if (is_sorted(*stack_a))
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
	{
		sa(stack_a);
		return ;
	}
	while (size > 3)
	{
		min_to_top(stack_a);
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;

	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}
