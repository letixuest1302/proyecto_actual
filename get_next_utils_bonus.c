/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:52:33 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 09:53:35 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *string, int character_to_find)
{
	char	*pointer;

	if (!string)
		return (NULL);
	pointer = (char *) string;
	while (*pointer && *pointer != character_to_find)
		pointer++;
	if (*pointer == character_to_find)
		return (pointer);
	return (NULL);
}

size_t	ft_strlen(const char *string)
{
	size_t	index;

	if (!string)
		return (0);
	index = 0;
	while (string[index])
		index++;
	return (index);
}

char	*ft_substr(char *string, size_t length)
{
	char	*substring;
	size_t	position;
	size_t	string_len;

	if (!string)
		return (NULL);
	string_len = ft_strlen(string);
	if (length > string_len)
		length = string_len;
	substring = malloc(length + 1);
	if (!substring)
		return (NULL);
	position = 0;
	while (position < length)
	{
		substring[position] = string[position];
		position++;
	}
	substring[position] = '\0';
	return (substring);
}

char	*ft_strjoin(char const *first_string, char const *second_string)
{
	size_t		total_length;
	char		*result_string;
	long long	count;
	int			aux_index;

	count = -1;
	if (!first_string && !second_string)
		return (NULL);
	if (!second_string)
		return (ft_substr((char *)first_string, ft_strlen(first_string)));
	if (!first_string)
		return (ft_substr((char *)second_string, ft_strlen(second_string)));
	total_length = ft_strlen(first_string) + ft_strlen(second_string);
	result_string = malloc(sizeof (char) * (total_length + 1));
	if (!result_string || (!first_string && !second_string))
		return (NULL);
	while (++count > -1 && first_string[count])
		result_string[count] = first_string[count];
	aux_index = count;
	count = -1;
	while (++count > -1 && second_string[count])
		result_string[count + aux_index] = second_string[count];
	result_string[total_length] = '\0';
	return (result_string);
}

void	*going_free(char *file_to_free, char *buffer_to_return)
{
	if (file_to_free)
		free(file_to_free);
	return (buffer_to_return);
}