/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:51:19 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 10:15:53 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int chrFind)
{
	char	*pointer;

	if (!str)
		return (NULL);
	pointer = (char *) str;
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

char	*ft_strjoin(char const *firstring, char const *secondstr)
{
	size_t		total_length;
	char		*result_str;
	long long	count;
	int			aux_index;

	count = -1;
	if (!firstring && !secondstr)
		return (NULL);
	if (!secondstr)
		return (ft_substr((char *)firstring, ft_strlen(firstring)));
	if (!firstring)
		return (ft_substr((char *)secondstr, ft_strlen(secondstr)));
	
	total_length = ft_strlen(firstring) + ft_strlen(secondstr);
	result_str = malloc(sizeof (char) * (total_length + 1));
	if (!result_str)
		return (NULL);
		
	while (++count > -1 && firstring[count])
		result_str[count] = firstring[count];
	aux_index = count;
	count = -1;
	while (++count > -1 && secondstr[count])
		result_str[count + aux_index] = secondstr[count];
	result_str[total_length] = '\0';
	return (result_str);
}

void	*going_free(char *fltofree, char *buftoreturn)
{
	if (fltofree)
		free(fltofree);
	return (buftoreturn);
}
