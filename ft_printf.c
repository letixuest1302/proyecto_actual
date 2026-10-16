/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:13:28 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/16 13:00:29 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	choose_impre(char *format_type, va_list val_box)
{
	int	let_now;

	let_now = 0;
	if (*format_type == 'c')
		let_now += ft_putchar((char)va_arg(val_box, int));
	else if (*format_type == 's')
		let_now += ft_putstr(va_arg(val_box, char *));
	else if (*format_type == '%')
		let_now += ft_putchar('%');
	else if (*format_type == 'd' || *format_type == 'i')
		let_now += ft_putnbr(va_arg(val_box, int));
	else if (*format_type == 'u')
		let_now += ft_putnbr(va_arg(val_box, unsigned int));
	else if (*format_type == 'x')
		let_now += ft_putstrm(ft_tolowercase(ft_itoah(va_arg(val_box,
							unsigned int))));
	else if (*format_type == 'X')
		let_now += ft_putstrm(ft_touppercase(ft_itoah(va_arg(val_box,
							unsigned int))));
	else if (*format_type == 'p')
		let_now += ft_putdir(va_arg(val_box, unsigned long));
	return (let_now);
}

int	ft_printf(const char *phr, ...)
{
	va_list	value_box;
	int		total_count;
	char	*thrgh_phr;

	if (!phr)
		return (-1);
	thrgh_phr = (char *)phr;
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
