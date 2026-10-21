/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:51:07 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 16:21:57 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*join(char *pack, char *txtrea, int byrea)
{
	char	*mixrea;

	txtrea[byrea] = '\0';
	if (!pack)
		mixrea = ft_substr(txtrea, ft_strlen(txtrea));
	else
	{
		mixrea = ft_strjoin(pack, txtrea);
		free(pack);
	}
	if (!mixrea)
		free(txtrea);
	return (mixrea);
}

static char	*gline(char *pack)
{
	char	*extractedline;
	char	*newlinepos;

	if (!pack || !pack[0])
		return (NULL);
	newlinepos = ft_strchr(pack, '\n');
	if (newlinepos)
		extractedline = ft_substr(pack, 1 + newlinepos - pack);
	else
		extractedline = ft_substr(pack, ft_strlen(pack));
	if (!extractedline)
	{
		free(pack);
		pack = NULL;
	}
	return (extractedline);
}

static char	*nline(char *pack)
{
	char	*remaindertxt;

	if (!pack[0] || (pack[0] == '\n' && !pack[1]))
	{
		free(pack);
		return (NULL);
	}
	remaindertxt = ft_strchr(pack, '\n');
	if (remaindertxt)
	{
		if (*remaindertxt == '\n')
			remaindertxt++;
		remaindertxt = ft_substr(remaindertxt, ft_strlen(remaindertxt));
	}
	free(pack);
	return (remaindertxt);
}

static char	*reader(int fd, char *pack)
{
	int		by_read;
	char	*read_buffer;

	by_read = 1;
	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	while (by_read > 0)
	{
		by_read = read(fd, read_buffer, BUFFER_SIZE);
		if (by_read <= 0)
		{
			free(read_buffer);
			if (by_read == 0)
				return (pack);
			return (going_fre(pack, NULL));
		}
		pack = join(pack, read_buffer, by_read);
		if (!pack || ft_strchr(pack, '\n'))
			return (going_fre(read_buffer, pack));
	}
	free(read_buffer);
	return (pack);
}

char	*get_next_line(int fd)
{
	static char	*pack[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pack[fd] = reader(fd, pack[fd]);
	if (!pack[fd])
		return (NULL);
	line = gline(pack[fd]);
	pack[fd] = nline(pack[fd]);
	return (line);
}
