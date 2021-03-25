/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:12:20 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/05 17:32:33 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_wordcount(char const *s, char c)
{
	int			i;
	int			wcount;

	i = 0;
	wcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			wcount++;
		}
	}
	return (wcount);
}

static char		*ft_wordsplit(char const *str, char c)
{
	char		*word;
	int			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char		**words;
	int			i;

	if (!s || !c)
	{
		words = malloc(sizeof(char *));
		words[0] = NULL;
		return (words);
	}
	if (!(words = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && *s != c)
		{
			words[i++] = ft_wordsplit(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	words[i] = NULL;
	return (words);
}

void			*ft_memset(void *str, int c, size_t nb)
{
	size_t		cont;
	char		*punt;

	cont = 0;
	punt = str;
	while (nb > cont)
	{
		punt[cont] = c;
		cont++;
	}
	return (str);
}

void			ft_bzero(void *str, size_t nb)
{
	nb = 0;
	ft_memset(str, 0, nb);
}
