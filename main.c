/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:43:36 by acornia           #+#    #+#             */
/*   Updated: 2026/11/03 15:50:55 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*flag;
	t_bench	bench;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	flag = NULL;
	if (!handle_args(argc, argv, &stack_a, &flag, &bench))
		return (error(stack_a, NULL));
	assign_index(stack_a);
	if (!is_sorted(stack_a))
		adaptative_sort(&stack_a, &stack_b, flag, &bench);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
