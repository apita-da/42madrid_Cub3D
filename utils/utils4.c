/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:32:17 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/13 11:36:42 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	if (n == 0)
		return (0);
	while (s1[cont] != '\0' && s2[cont] != '\0'
			&& s1[cont] == s2[cont] && (cont < n - 1))
	{
		cont++;
	}
	return ((unsigned char)s1[cont] - s2[cont]);
}

int			ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

void		print_mapa(t_big *big)
{
	int		i;
	char	**mapa;

	mapa = big->map.mapa;
	i = 0;
	while (mapa[i] != NULL)
	{
		printf("mapa: %s\n", mapa[i]);
		i++;
	}
}
