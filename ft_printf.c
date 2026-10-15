/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:13:28 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/14 15:37:21 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	choose_impre(char *format_type, va_list value_box)
{
	int	letter_now;

	letter_now = 0;
	if (*format_type == 'c')
		letter_now += ft_putchar((char) va_arg(value_box, int));
	else if (*format_type == 's')
		letter_now += ft_putstr(va_arg(value_box, char *));
	else if (*format_type == '%')
		letter_now += ft_putchar('%');
	else if (*format_type == 'd' || *format_type == 'i')
		letter_now += ft_putnbr(va_arg(value_box, int));
	else if (*format_type == 'u')
		letter_now += ft_putnbr(va_arg(value_box, unsigned int));
	else if (*format_type == 'x')
		letter_now += ft_putstrm(ft_tolowercase(ft_itoah(va_arg(value_box, unsigned int))));
	else if (*format_type == 'X')
		letter_now += ft_putstrm(ft_touppercase(ft_itoah(va_arg(value_box, unsigned int))));
	else if (*format_type == 'p')
		letter_now += ft_putdir(va_arg(value_box, unsigned long));
	return (letter_now);
}

int	ft_printf(const char *phr, ...)
{
	va_list	value_box;
	int		total_count;
	char	*thrgh_phr;

	if (!phr)
		return (-1);
	thrgh_phr = (char *) phr;
	total_count = 0;
	va_start(value_box, phr);
	while (*thrgh_phr)
	{
		if (*thrgh_phr == '%')
			total_count += choose_impre(++thrgh_phr, value_box);
		else
		{
			write(1, thrgh_phr, 1);
			total_count++;
		}
		thrgh_phr++;
	}
	va_end(value_box);
	return (total_count);
}