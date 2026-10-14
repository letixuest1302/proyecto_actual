/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:54:59 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/14 14:58:46 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    printf("ft_isalpha('g'): %d (Esperado: != 0)\n", ft_isalpha('g'));
    printf("ft_isalpha('5'): %d (Esperado: 0)\n", ft_isalpha('5'));
    return (0);
}
*/