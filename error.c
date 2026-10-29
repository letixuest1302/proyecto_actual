/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:20:04 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 13:12:34 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = (stack)->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
}

void	free_split(char	**split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	error(t_node *stack_a, char **split)
{
	if (stack_a)
		free_stack(stack_a);
	if (split)
		free_split(split);
	write (2, "Error\n", 6);
	return (1);
}
