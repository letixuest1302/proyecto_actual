/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:48:31 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 10:12:54 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *pack)
{
	int		by_read;
	char	*temporal_brick;

	by_read = 1;
	temporal_brick = malloc(sizeof (char) * (BUFFER_SIZE + 1)); // Reservamos un vaso para leer
	
	while (by_read > 0)
	{
		by_read = read(fd, temporal_brick, BUFFER_SIZE); // Leemos un trozo
		if (by_read <= 0)
		{
			going_free(temporal_brick, NULL);
			if (by_read == 0)
				return (pack); // Si llegamos al final del fd, devolvemos lo que tengamos
			free (pack);
			return (NULL);
		}
		pack = join(pack, temporal_brick, by_read); // Juntamos lo leído con lo que ya teníamos
		if (!pack)
			return (NULL);
		else if (ft_strchr(pack, '\n')) // Si ya encontramos un salto de línea, paramos de leer
			return (going_free(temporal_brick, pack));
	}
	free(temporal_brick);
	return (pack);
}

static char	*join(char *pack, char *read_now, int by_read)
{
	char	*temp;

	read_now[by_read] = 0; // Marcamos el final de la cadena
	if (!pack)
		temp = ft_substr(read_now, ft_strlen(read_now)); // Si la pack estaba vacía, copiamos lo nuevo
	else
		temp = going_free(pack, ft_strjoin(pack, read_now)); // Si ya tenía cosas, las unimos
	
	if (!temp)
		free (read_now);
	return (temp);
}

static char	*gline(char *pack)
{
	char	*current_line;
	char	*nlFinder;

	if (!pack || !pack[0])
		return (NULL);
	
	nlFinder = ft_strchr(pack, '\n'); // Buscamos dónde está el enter
	
	if (nlFinder)
		current_line = ft_substr(pack, 1 + nlFinder - pack); // Cortamos hasta el enter
	else
		current_line = ft_substr(pack, ft_strlen(pack)); // Si no hay enter, devolvemos todo lo que queda
		
	if (!current_line)
	{
		free (pack);
		pack = NULL;
	}
	return (current_line);
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
			excess++; // Avanzamos justo después del enter
		excess = ft_substr(excess, ft_strlen(excess)); // Guardamos el resto
	}
	free(pack); // Liberamos la mochila vieja
	return (excess); // Devolvemos la mochila actualizada con el excess
}

char	*get_next_line(int fd)
{
	static char	*pack; // Nuestra memoria que no se borra entre llamadas
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	// 1. Leemos del fd hasta tener al menos una línea completa en la pack
	pack = reader(fd, pack);
	if (!pack)
		return (NULL);
	
	// 2. Cortamos y sacamos la línea limpia que vamos a devolver
	current_line = gline(pack);
	
	// 3. Limpiamos la pack: quitamos la línea ya leída y dejamos solo lo excess
	pack = nline(pack);
	
	return (current_line);
}