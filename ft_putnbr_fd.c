/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:54:51 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/16 13:56:42 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(long n, int fd, int *count)
{
	unsigned long	num;
	char			nbr;

	if (fd < 0)
		return (0);
	if (n < 0)
	{
		*count += write(fd, "-", 1);
		num = (unsigned long)n;
		num = -num;
	}
	else
		num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd, count);
	nbr = (num % 10) + '0';
	*count += write(fd, &nbr, 1);
	return (*count);
}
/*
#include "ft_printf.h"

int	main(void)
{
    ft_putnbr_fd(42, 1, 0);
    
    return (0);
}
*/
