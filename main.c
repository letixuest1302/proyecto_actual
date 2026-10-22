/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:55:30 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/22 16:19:06 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("prueba.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
    close(fd);
    return (0);
}
