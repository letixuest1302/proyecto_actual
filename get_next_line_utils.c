/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:51:19 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 11:00:15 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int chrFind)
{
	char	*pointer;

	if (!str)
		return (NULL);
	pointer = (char *)str;
	while (*pointer && *pointer != chrFind)
		pointer++;
	if (*pointer == chrFind)
		return (pointer);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_substr(char *str, size_t length)
{
	char	*substr;
	size_t	pos;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (length > str_len)
		length = str_len;
	substr = malloc(length + 1);
	if (!substr)
		return (NULL);
	pos = 0;
	while (pos < length)
	{
		substr[pos] = str[pos];
		pos++;
	}
	substr[pos] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[len] = '\0';
	return (res);
}

void	*going_free(char *fltofree, char *buftoreturn)
{
	if (fltofree)
		free(fltofree);
	return (buftoreturn);
}
