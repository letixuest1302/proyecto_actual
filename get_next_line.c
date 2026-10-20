/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:48:31 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/20 18:30:37 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *backpack)
{
	int		bytes_leidos;
	char	*bloque_temporal;

	bytes_leidos = 1;
	bloque_temporal = malloc(sizeof (char) * (BUFFER_SIZE + 1)); // Reservamos un vaso para leer
	
	while (bytes_leidos > 0)
	{
		bytes_leidos = read(fd, bloque_temporal, BUFFER_SIZE); // Leemos un trozo
		if (bytes_leidos <= 0)
		{
			going_free(bloque_temporal, NULL);
			if (bytes_leidos == 0)
				return (backpack); // Si llegamos al final del fd, devolvemos lo que tengamos
			free (backpack);
			return (NULL);
		}
		backpack = join(backpack, bloque_temporal, bytes_leidos); // Juntamos lo leído con lo que ya teníamos
		if (!backpack)
			return (NULL);
		else if (ft_strchr(backpack, '\n')) // Si ya encontramos un salto de línea, paramos de leer
			return (going_free(bloque_temporal, backpack));
	}
	free(bloque_temporal);
	return (backpack);
}

static char	*join(char *backpack, char *leido_ahora, int bytes_leidos)
{
	char	*temp;

	leido_ahora[bytes_leidos] = 0; // Marcamos el final de la cadena
	if (!backpack)
		temp = ft_substr(leido_ahora, ft_strlen(leido_ahora)); // Si la backpack estaba vacía, copiamos lo nuevo
	else
		temp = going_free(backpack, ft_strjoin(backpack, leido_ahora)); // Si ya tenía cosas, las unimos
	
	if (!temp)
		free (leido_ahora);
	return (temp);
}

static char	*gline(char *backpack)
{
	char	*linea_actual;
	char	*posicion_salto;

	if (!backpack || !backpack[0])
		return (NULL);
	
	posicion_salto = ft_strchr(backpack, '\n'); // Buscamos dónde está el enter
	
	if (posicion_salto)
		linea_actual = ft_substr(backpack, 1 + posicion_salto - backpack); // Cortamos hasta el enter
	else
		linea_actual = ft_substr(backpack, ft_strlen(backpack)); // Si no hay enter, devolvemos todo lo que queda
		
	if (!linea_actual)
	{
		free (backpack);
		backpack = NULL;
	}
	return (linea_actual);
}

static char	*nline(char *backpack)
{
	char	*sobrante;

	if (!backpack[0] || (backpack[0] == '\n' && !backpack[1]))
	{
		free(backpack);
		return (NULL);
	}
	
	sobrante = ft_strchr(backpack, '\n');
	if (sobrante)
	{
		if (*sobrante == '\n')
			sobrante++; // Avanzamos justo después del enter
		sobrante = ft_substr(sobrante, ft_strlen(sobrante)); // Guardamos el resto
	}
	free(backpack); // Liberamos la mochila vieja
	return (sobrante); // Devolvemos la mochila actualizada con el sobrante
}

char	*get_next_line(int fd)
{
	static char	*backpack; // Nuestra memoria que no se borra entre llamadas
	char		*linea_actual;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
	// 1. Leemos del fd hasta tener al menos una línea completa en la backpack
	backpack = reader(fd, backpack);
	if (!backpack)
		return (NULL);
	
	// 2. Cortamos y sacamos la línea limpia que vamos a devolver
	linea_actual = gline(backpack);
	
	// 3. Limpiamos la backpack: quitamos la línea ya leída y dejamos solo lo sobrante
	backpack = nline(backpack);
	
	return (linea_actual);
}