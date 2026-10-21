/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:51:43 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/21 15:33:32 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *str, int chrfind);
char	*ft_substr(char *str, size_t length);
char	*ft_strjoin(char const *s1, char const *s2);

void	*going_free(char *fltofree, char *buftoreturn);

#endif 