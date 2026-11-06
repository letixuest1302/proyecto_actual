/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:08:19 by acornia & l       #+#    #+#             */
/*   Updated: 2026/11/06 12:45:05 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	index_max_pos(t_node *stack)
{
	int	max_idx;
	int	max_pos;
	int	current_pos;

	if (!stack)
		return (0);
	max_pos = 0;
	current_pos = 0;
	max_idx = stack->index;
	while (stack)
	{
		if (stack->index > max_idx)
		{
			max_idx = stack->index;
			max_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (max_pos);
}

int	index_min_pos(t_node *stack)
{
	int	min_idx;
	int	min_pos;
	int	current_pos;

	if (!stack)
		return (0);
	min_pos = 0;
	current_pos = 0;
	min_idx = stack->index;
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

int	ft_strcmp(const char *flag, const char *str)
{
	int	i;

	i = 0;
	while (flag[i] == str[i] && flag[i] != '\0')
		i++;
	return (flag[i] - str[i]);
}
