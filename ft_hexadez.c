/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadez.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:52:04 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/16 13:51:30 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numlen(unsigned long n)
{
	int	esp;

	esp = 1;
	while (n > 15)
	{
		n /= 16;
		esp++;
	}
	esp++;
	return (esp);
}

static void	numins(unsigned long temp, char *dst)
{
	char	rom;
	int		val;

	if (temp >= 16)
		numins((temp / 16), dst - 1);
	val = temp % 16;
	if (val >= 10)
		rom = val + 55;
	else
		rom = val + 48;
	dst[0] = rom;
}

char	*ft_itoah(unsigned long original_num)
{
	char			*final_text;
	unsigned long	num_copied;
	int				text_len;

	num_copied = original_num;
	text_len = numlen(num_copied);
	final_text = malloc(sizeof(char) * text_len);
	if (!final_text)
		return (NULL);
	final_text[text_len - 1] = '\0';
	numins(num_copied, &final_text[text_len - 2]);
	return (final_text);
}
