/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:34:35 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 11:14:04 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init(t_big *big)
{
	init_ray2(big);
	init_mov(big);
	init_spr(big);
}

void		init_map(t_big *big)
{
	big->map.mapa = NULL;
	big->map.line = NULL;
	big->map.parse = NULL;
	big->map.tfile = NULL;
	big->map.fd = 0;
	big->map.res_x = 0;
	big->map.res_y = 0;
	big->map.num_line = 0;
	big->map.face = 0;
	big->map.len = 0;
	big->map.cel_colors = -1;
	big->map.flo_colors = -1;
	big->map.north = NULL;
	big->map.south = NULL;
	big->map.west = NULL;
	big->map.east = NULL;
	big->map.sprite = NULL;
	big->map.num_sprite = 0;
	big->check = 0;
	big->c_map = 0;
	big->player = 0;
	big->i = 0;
	init(big);
}

void		pos_init(t_big *big)
{
	int		i;
	int		j;
	char	**mapa;

	mapa = big->map.mapa;
	i = -1;
	while (mapa[++i] != NULL)
	{
		j = 0;
		while (mapa[i][j] != '\0')
		{
			if (mapa[i][j] == 'N' || mapa[i][j] == 'S' || mapa[i][j] == 'W'
				|| mapa[i][j] == 'E')
			{
				big->map.pos_x = (double)i + 0.5;
				big->map.pos_y = (double)j + 0.5;
				big->map.face = mapa[i][j];
				initial_pos(big);
				big->player++;
			}
			j++;
		}
		if (big->player > 1)
			map_error("more tha 1 player\n");
	}
}

void		initial_pos(t_big *big)
{
	double	angle;

	angle = 0;
	if (big->map.face == 'N' && (big->ray.plane_x = 0.5))
		angle = (M_PI / 2) + 0.01;
	else if (big->map.face == 'S' && (big->ray.plane_x = -0.5))
		angle = (3 * M_PI / 2) + 0.01;
	else if (big->map.face == 'E' && (big->ray.plane_y = 0.66))
		angle = 0.01;
	else if (big->map.face == 'W' && (big->ray.plane_y = -0.66))
		angle = (M_PI) + 0.01;
	big->ray.dir_x = cos(angle);
	big->ray.dir_y = -sin(angle);
	if (big->map.face == 'N' || big->map.face == 'S' || big->map.face == 'E' ||
		big->map.face == 'W')
		big->map.mapa[(int)big->map.pos_x][(int)big->map.pos_y] = '0';
}
