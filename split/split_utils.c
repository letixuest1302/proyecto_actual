/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:43:36 by acornia           #+#    #+#             */
/*   Updated: 2026/10/27 14:06:45 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	length;
	size_t	i;

	if (!str)
		return (NULL);
	length = ft_strlen(str);
	if (length < start)
		return (ft_strdup(""));
	if (len > length - start)
		len = length - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && str[start + i] != '\0')
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	length;
	char	*res;

	length = ft_strlen(str);
	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, str, length + 1);
	return (res);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*src_str;
	unsigned char		*dst_str;
	size_t				i;

	i = 0;
	dst_str = (unsigned char *)dst;
	src_str = (const unsigned char *)src;
	while (i < n)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	return (dst_str);
}
