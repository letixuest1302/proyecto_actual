/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:43:36 by acornia           #+#    #+#             */
/*   Updated: 2026/11/04 14:50:02 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_bench	bench;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!handle_args(argc, argv, &stack_a, &bench))
		return (error(stack_a, NULL));
	assign_index(stack_a);
	if (!is_sorted(stack_a) || bench.enabled)
		adaptative_sort(&stack_a, &stack_b, bench.flag, &bench);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
