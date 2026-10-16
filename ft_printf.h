/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:09:14 by lesainz           #+#    #+#             */
/*   Updated: 2026/10/16 13:02:41 by lesainz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>

char	*ft_tolowercase(char *s);
char	*ft_touppercase(char *s);
char	*ft_itoah(unsigned long original_num);
int		ft_printf(const char *phr, ...);
int		ft_putchar(char c);
int		ft_putnbr(long i);
int		ft_putstr(char *s);
int		ft_putstrm(char *s);
int		ft_putdir(unsigned long p);
int		ft_putnbr_fd(long n, int fd, int *count);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalpha(int c);
size_t	ft_strlen(const char *line);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
