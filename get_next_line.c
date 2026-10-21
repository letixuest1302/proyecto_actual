/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:56:29 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 10:56:45 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char *pack, char *read_now, int by_read)
{
	char	*temp;

	read_now[by_read] = '\0';
	if (!pack)
		temp = ft_substr(read_now, 0, ft_strlen(read_now));
	else
		temp = going_free(pack, ft_strjoin(pack, read_now));
	if (!temp)
		free(read_now);
	return (temp);
}

static char	*gline(char *pack)
{
	char	*lnow;
	char	*nlfinder;

	if (!pack || !pack[0])
		return (NULL);
	nlfinder = ft_strchr(pack, '\n');
	if (nlfinder)
		lnow = ft_substr(pack, 0, 1 + nlfinder - pack);
	else
		lnow = ft_substr(pack, 0, ft_strlen(pack));
	if (!lnow)
	{
		free(pack);
		pack = NULL;
	}
	return (lnow);
}

static char	*nline(char *pack)
{
	char	*excess;

	if (!pack[0] || (pack[0] == '\n' && !pack[1]))
	{
		free(pack);
		return (NULL);
	}
	excess = ft_strchr(pack, '\n');
	if (excess)
	{
		if (*excess == '\n')
			excess++;
		excess = ft_substr(excess, 0, ft_strlen(excess));
	}
	free(pack);
	return (excess);
}

static char	*reader(int fd, char *pack)
{
	int		by_read;
	char	*tempbrick;

	by_read = 1;
	tempbrick = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tempbrick)
		return (NULL);
	while (by_read > 0)
	{
		by_read = read(fd, tempbrick, BUFFER_SIZE);
		if (by_read <= 0)
		{
			free(tempbrick);
			if (by_read == 0)
				return (pack);
			free(pack);
			return (NULL);
		}
		pack = join(pack, tempbrick, by_read);
		if (!pack || ft_strchr(pack, '\n'))
			return (going_free(tempbrick, pack));
	}
	free(tempbrick);
	return (pack);
}

char	*get_next_line(int fd)
{
	static char	*pack;
	char		*lnow;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pack = reader(fd, pack);
	if (!pack)
		return (NULL);
	lnow = gline(pack);
	pack = nline(pack);
	return (lnow);
}
