/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:54:11 by acornia           #+#    #+#             */
/*   Updated: 2026/10/27 14:06:44 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);

#endif