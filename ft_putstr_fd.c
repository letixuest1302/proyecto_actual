/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:55:25 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/14 14:57:33 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
	{
		return ;
	}
	write(fd, s, ft_strlen(s));
}
/*
int main(void)
{
    ft_putstr_fd("Hola descriptor\n", 1);
    return (0);
}*/