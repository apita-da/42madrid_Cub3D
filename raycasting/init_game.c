/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:11:45 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 10:11:43 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_big *big)
{
	get_texture(big);
	get_spr_tex(big);
}

void	init_mov(t_big *big)
{
	big->mov.key_w = 0;
	big->mov.key_s = 0;
	big->mov.key_a = 0;
	big->mov.key_d = 0;
	big->mov.key_q = 0;
	big->mov.key_e = 0;
}

void	init_ray(t_big *big)
{
	big->ray.x = 0;
	big->ray.step_x = 0;
	big->ray.step_y = 0;
	big->ray.hit = 0;
	big->ray.side = 0;
	big->ray.map_x = 0;
	big->ray.map_y = 0;
	big->ray.dir_x = 0;
	big->ray.dir_y = 0;
	big->ray.plane_x = 0;
	big->ray.plane_y = 0;
	big->ray.camera_x = 0;
	big->ray.raydir_x = 0;
	big->ray.raydir_y = 0;
	big->ray.sidedist_x = 0;
	big->ray.sidedist_y = 0;
	big->ray.deltadist_x = 0;
	big->ray.deltadist_y = 0;
	big->ray.wall_x = 0;
	big->ray.wall_y = 0;
	big->ray.olddir_x = 0;
	big->ray.oldplane_x = 0;
}

void	init_ray2(t_big *big)
{
	init_ray(big);
	big->ray.speed = 0.09;
	big->ray.rotspeed = big->ray.speed * 0.35;
	big->ray.drawstart = 0;
	big->ray.drawstart = 0;
	big->ray.lineheight = 0;
	big->ray.perpwalldist = 0;
	big->ray.tex_pos = 0;
	big->ray.step = 0;
	big->ray.tex_color = 0;
	big->ray.tex_x = 0;
	big->ray.tex_y = 0;
	big->ray.wall = 0;
}

void	init_spr(t_big *big)
{
	big->spr.spr_ptr = NULL;
	big->spr.spr_wi = 0;
	big->spr.spr_he = 0;
	big->spr.spr_size = 0;
	big->spr.sprite_x = 0;
	big->spr.sprite_y = 0;
	big->spr.invdet = 0;
	big->spr.transformx = 0;
	big->spr.transformy = 0;
	big->spr.spritescreenx = 0;
	big->spr.drawstarty = 0;
	big->spr.drawendy = 0;
	big->spr.drawstartx = 0;
	big->spr.drawendx = 0;
	big->spr.stripe = 0;
	big->spr.tex_x = 0;
	big->spr.tex_y = 0;
	big->spr.spritedist = 0;
}
