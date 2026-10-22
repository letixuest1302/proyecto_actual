/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:51:37 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/22 13:06:02 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# define TILL_CHAR '\n'

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *str, int chrfind);
char	*ft_substr(char *str, size_t length);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

void	*going_fre(char *fltofree, char *buftoreturn);

#endif
