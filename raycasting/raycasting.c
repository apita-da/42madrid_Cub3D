/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:42:37 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/12 09:01:42 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		calc_step(t_big *big)
{
	if (big->ray.raydir_x < 0)
	{
		big->ray.step_x = -1;
		big->ray.sidedist_x = (big->map.pos_x -
			big->ray.map_x) * big->ray.deltadist_x;
	}
	else
	{
		big->ray.step_x = 1;
		big->ray.sidedist_x = (big->ray.map_x + 1.0 -
			big->map.pos_x) * big->ray.deltadist_x;
	}
	if (big->ray.raydir_y < 0)
	{
		big->ray.step_y = -1;
		big->ray.sidedist_y = (big->map.pos_y -
			big->ray.map_y) * big->ray.deltadist_y;
	}
	else
	{
		big->ray.step_y = 1;
		big->ray.sidedist_y = (big->ray.map_y + 1.0 -
			big->map.pos_y) * big->ray.deltadist_y;
	}
}

void		calc_ray_hit(t_big *big)
{
	big->ray.hit = 0;
	while (big->ray.hit == 0)
	{
		if (big->ray.sidedist_x < big->ray.sidedist_y)
		{
			big->ray.sidedist_x += big->ray.deltadist_x;
			big->ray.map_x += big->ray.step_x;
			big->ray.side = 0;
		}
		else
		{
			big->ray.sidedist_y += big->ray.deltadist_y;
			big->ray.map_y += big->ray.step_y;
			big->ray.side = 1;
		}
		if (big->map.mapa[big->ray.map_x][big->ray.map_y] == '1')
			big->ray.hit = 1;
	}
}

void		calc_wall(t_big *big)
{
	int		h;

	h = big->map.res_y;
	if (big->ray.side == 0)
		big->ray.perpwalldist = (big->ray.map_x - big->map.pos_x +
			(1 - big->ray.step_x) / 2) / big->ray.raydir_x;
	else
		big->ray.perpwalldist = (big->ray.map_y - big->map.pos_y +
			(1 - big->ray.step_y) / 2) / big->ray.raydir_y;
	if (big->ray.perpwalldist == 0)
		big->ray.perpwalldist = 0.1;
	big->ray.lineheight = (int)(h / big->ray.perpwalldist);
	big->ray.drawstart = (-big->ray.lineheight / 2) + (h / 2);
	if (big->ray.drawstart < 0)
		big->ray.drawstart = 0;
	big->ray.drawend = (big->ray.lineheight / 2) + (h / 2);
	if (big->ray.drawend >= h)
		big->ray.drawend = h - 1;
}

void		draw_map(t_big *big)
{
	int		i;

	i = 0;
	while (i <= big->ray.drawstart)
	{
		my_mlx_pixel_put(big, big->ray.x, i, big->map.cel_colors);
		i++;
	}
	while (i > big->ray.drawstart && i <= big->ray.drawend)
	{
		print_textura(big, i);
		my_mlx_pixel_put(big, big->ray.x, i, big->ray.tex_color);
		i++;
	}
	while (i > big->ray.drawend && i < big->map.res_y)
	{
		my_mlx_pixel_put(big, big->ray.x, i, big->map.flo_colors);
		i++;
	}
}

int			raycasting(t_big *big)
{
	big->ray.x = 0;
	big->spr.zbuffer = malloc(sizeof(int) * big->map.res_x);
	while (big->ray.x < big->map.res_x)
	{
		big->ray.camera_x = 2 * big->ray.x / (double)big->map.res_x - 1;
		big->ray.raydir_x = big->ray.dir_x +
			big->ray.plane_x * big->ray.camera_x;
		big->ray.raydir_y = big->ray.dir_y +
			big->ray.plane_y * big->ray.camera_x;
		big->ray.map_x = (int)big->map.pos_x;
		big->ray.map_y = (int)big->map.pos_y;
		big->ray.deltadist_x = fabs(1 / big->ray.raydir_x);
		big->ray.deltadist_y = fabs(1 / big->ray.raydir_y);
		calc_step(big);
		calc_ray_hit(big);
		calc_wall(big);
		draw_map(big);
		if (big->map.num_sprite > 0)
			big->spr.zbuffer[big->ray.x] = big->ray.perpwalldist;
		big->ray.x++;
	}
	if (big->map.num_sprite > 0)
		spr_raycasting(big);
	return (0);
}
