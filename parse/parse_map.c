/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:35:17 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 10:15:36 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		valid_map(t_big *big)
{
	int		i;

	i = 0;
	while (i < big->map.num_line)
	{
		if (big->map.mapa[i][0] == '0' || big->map.mapa[i][0] == '2')
			return (1);
		if (big->map.mapa[i][big->map.len - 1] == '0'
			|| big->map.mapa[i][big->map.len - 1] == '2')
			return (1);
		i++;
	}
	i = 0;
	while (i < big->map.len)
	{
		if (big->map.mapa[0][i] == '0' || big->map.mapa[0][i] == '2')
			return (1);
		if (big->map.mapa[big->map.num_line - 1][i] == '0'
			|| big->map.mapa[big->map.num_line - 1][i] == '2')
			return (1);
		i++;
	}
	return (0);
}

void	floodfill(int x, int y, t_big *big)
{
	if (x < 0 || x >= big->map.num_line || y < 0 || y >= big->map.len)
		return ;
	if (big->map.mapa[x][y] != 'X')
		return ;
	if (big->map.mapa[x][y] == '0')
		return ;
	if (big->map.mapa[x][y] == 'X')
		big->map.mapa[x][y] = '0';
	floodfill(x - 1, y, big);
	floodfill(x + 1, y, big);
	floodfill(x, y - 1, big);
	floodfill(x, y + 1, big);
}

void	fill_map(t_big *big)
{
	int		x;
	int		y;

	x = (int)big->map.pos_x;
	y = (int)big->map.pos_y;
	floodfill(x, y, big);
	if (valid_map(big) == 1)
		map_error("Mapa abierto\n");
}

void	replace_sprites(t_big *big)
{
	int i;

	i = 0;
	while (i < big->map.num_sprite)
	{
		big->map.mapa[(int)big->spr.spr_x[i]][(int)big->spr.spr_y[i]] = '2';
		i++;
	}
}

void	get_map(t_big *big)
{
	big->map.num_sprite = cont_spr(big->map.parse);
	check_caracteres(big);
	big->map.mapa = ft_split(big->map.parse, '\n');
	pos_init(big);
	free(big->map.parse);
	get_sprites(big);
	make_square(big);
	fill_map(big);
	replace_sprites(big);
}
