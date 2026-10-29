/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acornia <acornia@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:32:21 by acornia           #+#    #+#             */
/*   Updated: 2026/10/29 12:12:08 by acornia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static void	free_array(char **tab, int i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}

static char	**fill_tab(char **tab, char const *str, char c)
{
	int		i;
	size_t	len;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			len = 0;
			while (str[len] && str[len] != c)
				len++;
			tab[i] = ft_substr(str, 0, len);
			if (!tab[i])
			{
				free_array(tab, i);
				return (NULL);
			}
			i++;
			str += len;
		}
		else
			str++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!tab)
		return (NULL);
	return (fill_tab(tab, str, c));
}
