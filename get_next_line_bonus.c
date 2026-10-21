/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:51:07 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 10:35:16 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *join(char *pack, char *read_text, int bytes_read)
{
    char    *combined_text;

    read_text[bytes_read] = 0;
    if (!pack)
        combined_text = ft_strdup(read_text);
    else
    {
        combined_text = ft_strjoin(pack, read_text);
        free(pack);
    }
    if (!combined_text)
        free(read_text);
    return (combined_text);
}

static char	*gline(char *pack)
{
	char	*extracted_line;
	char	*newline_position;

	if (!pack || !pack[0])
		return (NULL);
	newline_position = ft_strchr(pack, '\n');
	if (newline_position)
		extracted_line = ft_substr(pack, 1 + newline_position - pack);
	else
		extracted_line = ft_substr(pack, ft_strlen(pack));
	if (!extracted_line)
	{
		free (pack);
		pack = NULL;
	}
	return (extracted_line);
}

static char	*nline(char *pack)
{
	char	*remainder_text;

	if (!pack[0] || (pack[0] == '\n' && !pack[1]))
	{
		free(pack);
		return (NULL);
	}
	remainder_text = ft_strchr(pack, '\n');
	if (remainder_text)
	{
		if (*remainder_text == '\n')
			remainder_text++;
		remainder_text = ft_substr(remainder_text, ft_strlen(remainder_text));
	}
	free(pack);
	return (remainder_text);
}

static char	*reader(int fd, char *pack)
{
	int		bytes_read;
	char	*read_buffer;

	bytes_read = 1;
	read_buffer = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			going_free(read_buffer, NULL);
			if (bytes_read == 0)
				return (pack);
			return (going_free(pack, NULL));
		}
		pack = join(pack, read_buffer, bytes_read);
		if (!pack)
			return (NULL);
		else if (ft_strchr(pack, '\n'))
			return (going_free(read_buffer, pack));
	}
	free(read_buffer);
	read_buffer = NULL;
	return (pack);
}

char	*get_next_line(int fd)
{
	static char	*pack[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	pack[fd] = reader(fd, pack[fd]);
	if (!pack[fd])
	{
		return (NULL);
	}
	line = gline(pack[fd]);
	pack[fd] = nline(pack[fd]);
	return (line);
}
