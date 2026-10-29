/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:54:35 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 13:12:33 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process(char *str, t_node **stack)
{
	long	value;

	if (!numbers(str))
		return (0);
	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	if (duplicate(*stack, (int)value))
		return (0);
	if (!add_back(stack, (int)value))
		return (0);
	return (1);
}

static int	parse_array(char **split, t_node **stack)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!process(split[i], stack))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, int start, t_node **stack)
{
	char	**split;

	if (argc - start == 1)
	{
		split = ft_split(argv[start], ' ');
		if (!split || !split[0])
			return (0);
		if (!parse_array(split, stack))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
	}
	else
	{
		if (!parse_array(argv + start, stack))
			return (0);
	}
	return (1);
}
