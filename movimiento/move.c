/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:07:21 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/10 17:59:43 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_down(t_big *big)
{
	if (big->mov.key_s == 1)
	{
		if (big->map.mapa[(int)(big->map.pos_x - big->ray.dir_x *
			big->ray.speed)][(int)(big->map.pos_y)] == '0')
			big->map.pos_x -= big->ray.dir_x * big->ray.speed;
		if (big->map.mapa[(int)(big->map.pos_x)]
			[(int)(big->map.pos_y - big->ray.dir_y * big->ray.speed)] == '0')
			big->map.pos_y -= big->ray.dir_y * big->ray.speed;
	}
}

void	move_up(t_big *big)
{
	if (big->mov.key_w == 1)
	{
		if (big->map.mapa[(int)(big->map.pos_x + big->ray.dir_x *
			big->ray.speed)][(int)(big->map.pos_y)] == '0')
			big->map.pos_x += big->ray.dir_x * big->ray.speed;
		if (big->map.mapa[(int)(big->map.pos_x)]
			[(int)(big->map.pos_y + big->ray.dir_y * big->ray.speed)] == '0')
			big->map.pos_y += big->ray.dir_y * big->ray.speed;
	}
}

void	move_right_left(t_big *big)
{
	if (big->mov.key_d == 1)
	{
		if (big->map.mapa[(int)(big->map.pos_x + big->ray.plane_x *
			big->ray.speed)][(int)(big->map.pos_y)] == '0')
			big->map.pos_x += big->ray.plane_x * big->ray.speed;
		if (big->map.mapa[(int)(big->map.pos_x)]
			[(int)(big->map.pos_y + big->ray.plane_y * big->ray.speed)] == '0')
			big->map.pos_y += big->ray.plane_y * big->ray.speed;
	}
	else if (big->mov.key_a == 1)
	{
		if (big->map.mapa[(int)(big->map.pos_x - big->ray.plane_x *
			big->ray.speed)][(int)(big->map.pos_y)] == '0')
			big->map.pos_x -= big->ray.plane_x * big->ray.speed;
		if (big->map.mapa[(int)(big->map.pos_x)]
			[(int)(big->map.pos_y - big->ray.plane_y * big->ray.speed)] == '0')
			big->map.pos_y -= big->ray.plane_y * big->ray.speed;
	}
}

void	move_rot_r(t_big *big)
{
	if (big->mov.key_e == 1)
	{
		big->ray.olddir_x = big->ray.dir_x;
		big->ray.dir_x = big->ray.dir_x * cos(big->ray.rotspeed) -
			big->ray.dir_y * sin(big->ray.rotspeed);
		big->ray.dir_y = big->ray.olddir_x * sin(big->ray.rotspeed) +
			big->ray.dir_y * cos(big->ray.rotspeed);
		big->ray.oldplane_x = big->ray.plane_x;
		big->ray.plane_x = big->ray.plane_x * cos(big->ray.rotspeed) -
			big->ray.plane_y * sin(big->ray.rotspeed);
		big->ray.plane_y = big->ray.oldplane_x * sin(big->ray.rotspeed) +
		big->ray.plane_y * cos(big->ray.rotspeed);
	}
}

void	move_rot_l(t_big *big)
{
	if (big->mov.key_q == 1)
	{
		big->ray.olddir_x = big->ray.dir_x;
		big->ray.dir_x = big->ray.dir_x * cos(-big->ray.rotspeed) -
			big->ray.dir_y * sin(-big->ray.rotspeed);
		big->ray.dir_y = big->ray.olddir_x * sin(-big->ray.rotspeed) +
			big->ray.dir_y * cos(-big->ray.rotspeed);
		big->ray.oldplane_x = big->ray.plane_x;
		big->ray.plane_x = big->ray.plane_x * cos(-big->ray.rotspeed) -
			big->ray.plane_y * sin(-big->ray.rotspeed);
		big->ray.plane_y = big->ray.oldplane_x * sin(-big->ray.rotspeed) +
			big->ray.plane_y * cos(-big->ray.rotspeed);
	}
}
