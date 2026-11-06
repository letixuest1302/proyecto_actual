/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:53:13 by acornia & l       #+#    #+#             */
/*   Updated: 2026/11/06 12:45:09 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_node **stack_a, t_bench *bench)
{
	int	max_idx;

	if (is_sorted(*stack_a))
		return ;
	max_idx = index_max_pos(*stack_a);
	if (max_idx == 0)
		ra(stack_a, bench);
	else if (max_idx == 1)
		rra(stack_a, bench);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, bench);
}

void	sort_five(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	size;
	int	min_idx;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		min_idx = index_min_pos(*stack_a);
		if (min_idx <= size / 2)
		{
			while (min_idx-- > 0)
				ra(stack_a, bench);
		}
		else
		{
			while (min_idx++ < size)
				rra(stack_a, bench);
		}
		pb (stack_a, stack_b, bench);
		size--;
	}
	sort_three(stack_a, bench);
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}

int	handle_small_cases(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	size;

	size = stack_size(*stack_a);
	if (size <= 1 || is_sorted(*stack_a))
		return (1);
	if (size == 2)
		sa(stack_a, bench);
	else if (size == 3)
		sort_three(stack_a, bench);
	else if (size <= 5)
		sort_five(stack_a, stack_b, bench);
	else
		return (0);
	return (1);
}
