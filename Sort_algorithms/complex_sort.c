/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:00:59 by acornia           #+#    #+#             */
/*   Updated: 2026/11/06 12:45:23 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(t_node *stack)
{
	int	max_bits;
	int	max_index;

	max_index = stack_size(stack) - 1;
	max_bits = 0;
	while ((max_index >> max_bits) > 0)
		max_bits++;
	return (max_bits);
}

void	complex_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (handle_small_cases(stack_a, stack_b, bench))
		return ;
	i = 0;
	max_bits = get_max_bits(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		size = stack_size(*stack_a);
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a, bench);
			else
				pb(stack_a, stack_b, bench);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, bench);
		i++;
	}
}
