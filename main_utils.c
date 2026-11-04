/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia & lesainz <acornia@student.42ma    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 15:25:07 by acornia & l       #+#    #+#             */
/*   Updated: 2026/11/04 11:16:09 by acornia & l      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_bench(t_bench *bench)
{
	bench->enabled = 0;
	bench->disorder = 0.0f;
	bench->strategy = NULL;
	bench->complexity = NULL;
	bench->flag = NULL;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total_ops = 0;
}

int	handle_args(int argc, char **argv, t_node **stack, t_bench *bench)
{
	int	start;

	start = 1;
	init_bench(bench);
	while (start < argc)
	{
		if (ft_strcmp(argv[start], "--bench") == 0)
			bench->enabled = 1;
		else if (ft_strcmp(argv[start], "--simple") == 0
			|| ft_strcmp(argv[start], "--medium") == 0
			|| ft_strcmp(argv[start], "--complex") == 0
			|| ft_strcmp(argv[start], "--adaptive") == 0)
			bench->flag = argv[start];
		else
			break ;
		start++;
	}
	if (start >= argc)
		return (0);
	return (parse_args(argc, argv, start, stack));
}
