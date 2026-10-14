/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:54:51 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/14 15:22:41 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(long n, int fd, int *count)
{
	char	nbr;

	if (fd < 0)
		return (0);
	nbr = n;
	if (n == -2147483648)
	{
		*count = write(fd, "-2147483648", 11);
		return (*count);
	}
	if (nbr < 0)
	{
		*count = write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd, count);
	nbr = 48 + (n % 10);
	*count += write(fd, &nbr, 1);
	return (*count)
}
/*
#include "ft_printf.h"

int	main(void)
{
    ft_putnbr_fd(42, 1, 0);
    
    return (0);
}
*/
