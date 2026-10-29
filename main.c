/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:43:36 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 13:12:32 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *flag)
{
	if (!flag)
		return (0);
	if (flag[0] == '-' && flag[1] == '-')
		return (1);
	return (0);
}

static int	handle_args(int argc, char **argv, t_node **stack, char **flag)
{
	int	start;

	start = 1;
	if (is_flag(argv[1]))
	{
		*flag = argv[1];
		start = 2;
	}
	if (start >= argc)
		return (0);
	if (!parse_args(argc, argv, start, stack))
		return (0);
	return (1);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*flag;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	flag = NULL;
	if (!handle_args(argc, argv, &stack_a, &flag))
		return (error(stack_a, NULL));
	assign_index(stack_a);
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b, flag);
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
