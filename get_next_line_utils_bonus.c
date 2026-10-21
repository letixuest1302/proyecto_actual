/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:52:33 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 16:22:36 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int chrfind)
{
	char	*pointer;

	if (!str)
		return (NULL);
	pointer = (char *) str;
	while (*pointer && *pointer != chrfind)
		pointer++;
	if (*pointer == chrfind)
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

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t		tot_length;
	char		*result_str;
	long long	count;
	int			aux_index;

	count = -1;
	if (!str1 && !str2)
		return (NULL);
	if (!str2)
		return (ft_substr((char *)str1, ft_strlen(str1)));
	if (!str1)
		return (ft_substr((char *)str2, ft_strlen(str2)));
	tot_length = ft_strlen(str1) + ft_strlen(str2);
	result_str = malloc(sizeof (char) * (tot_length + 1));
	if (!result_str || (!str1 && !str2))
		return (NULL);
	while (++count > -1 && str1[count])
		result_str[count] = str1[count];
	aux_index = count;
	count = -1;
	while (++count > -1 && str2[count])
		result_str[count + aux_index] = str2[count];
	result_str[tot_length] = '\0';
	return (result_str);
}

void	*going_fre(char *fltofree, char *buftoreturn)
{
	if (fltofree)
		free(fltofree);
	return (buftoreturn);
}
