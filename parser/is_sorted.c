/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:52:31 by acornia           #+#    #+#             */
/*   Updated: 2026/10/30 12:30:48 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

float	disorder_index(t_node *stack)
{
	float	total_pairs;
	float	mistakes;
	t_node	*current;
	t_node	*compare;

	if (!stack || !stack->next)
		return (0.0f);
	mistakes = 0.0f;
	total_pairs = 0.0f;
	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs += 1.0f;
			if (current->value > compare->value)
				mistakes += 1.0f;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0.0f)
		return (0.0f);
	return (mistakes / total_pairs);
}
