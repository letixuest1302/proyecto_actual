/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:00:00 by acornia           #+#    #+#             */
/*   Updated: 2026/10/28 10:29:24 by lesainz          ###   ########.fr       */
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

int	parse_args(int argc, char **argv, t_node **stack)
{
	char	**split;
	int		ok;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (0);
		ok = (split[0] != NULL) && parse_array(split, stack);
		free_split(split);
		return (ok);
	}
	return (parse_array(argv + 1, stack));
}
