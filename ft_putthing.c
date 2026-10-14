/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:51:39 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/14 15:40:39 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putnbr(long i)
{
	int	j;
	int	s;

	s = 0;
	j = ft_putnbr_fd(i, 1, &s);
	return (j);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
