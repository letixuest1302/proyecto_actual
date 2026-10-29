/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:58:05 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 13:16:37 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	medium_sort(t_node **stack_a, t_node **stack_b)
{
	write(1, "Esto es medium\n", 15);
	simple_sort(stack_a, stack_b);
}
