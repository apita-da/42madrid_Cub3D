/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:35:07 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/10 17:59:22 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_drawstartend(t_big *big)
{
	big->spr.spr_he = abs((int)(big->map.res_y / big->spr.transformy));
	big->spr.drawstarty = (-big->spr.spr_he / 2) + (big->map.res_y / 2);
	if (big->spr.drawstarty < 0)
		big->spr.drawstarty = 0;
	big->spr.drawendy = (big->spr.spr_he / 2) + (big->map.res_y / 2);
	if (big->spr.drawendy >= big->map.res_y)
		big->spr.drawendy = big->map.res_y - 1;
	big->spr.spr_wi = abs((int)(big->map.res_y / big->spr.transformy));
	big->spr.drawstartx = (-big->spr.spr_wi / 2) + big->spr.spritescreenx;
	if (big->spr.drawstartx < 0)
		big->spr.drawstartx = 0;
	big->spr.drawendx = (big->spr.spr_wi / 2) + big->spr.spritescreenx;
	if (big->spr.drawendx >= big->map.res_x)
		big->spr.drawendx = big->map.res_x - 1;
}

void	calculate_transform(int i, t_big *big)
{
	big->spr.sprite_x = big->spr.spr_x[i] - big->map.pos_x;
	big->spr.sprite_y = big->spr.spr_y[i] - big->map.pos_y;
	big->spr.invdet = 1.0 / (big->ray.plane_x * big->ray.dir_y
		- big->ray.dir_x * big->ray.plane_y);
	big->spr.transformx = big->spr.invdet * (big->ray.dir_y *
		big->spr.sprite_x - big->ray.dir_x * big->spr.sprite_y);
	big->spr.transformy = big->spr.invdet * (-big->ray.plane_y *
		big->spr.sprite_x + big->ray.plane_x * big->spr.sprite_y);
	big->spr.spritescreenx = (int)((big->map.res_x / 2) *
		(1 + big->spr.transformx / big->spr.transformy));
}

void	tmp(t_big *big, int i, int j)
{
	double	tmp_x;
	double	tmp_y;

	big->spr.spritedist = ((big->map.pos_x - big->spr.spr_x[j]) *
		(big->map.pos_x - big->spr.spr_x[j]) +
		(big->map.pos_y - big->spr.spr_y[j]) *
		(big->map.pos_y - big->spr.spr_y[j]));
	tmp_x = big->spr.spr_x[i];
	tmp_y = big->spr.spr_y[i];
	big->spr.spr_x[i] = big->spr.spr_x[i + 1];
	big->spr.spr_y[i] = big->spr.spr_y[i + 1];
	big->spr.spr_x[i + 1] = tmp_x;
	big->spr.spr_y[i + 1] = tmp_y;
}

void	sort_spr(t_big *big)
{
	int	i;
	int	j;

	i = 0;
	while (i < big->map.num_sprite - 1)
	{
		big->spr.spritedist = ((big->map.pos_x - big->spr.spr_x[i]) *
			(big->map.pos_x - big->spr.spr_x[i]) +
			(big->map.pos_y - big->spr.spr_y[i]) *
			(big->map.pos_y - big->spr.spr_y[i]));
		j = i + 1;
		while (j < big->map.num_sprite)
		{
			if (((big->map.pos_x - big->spr.spr_x[j]) *
				(big->map.pos_x - big->spr.spr_x[j]) +
				(big->map.pos_y - big->spr.spr_y[j]) *
				(big->map.pos_y - big->spr.spr_y[j])) > big->spr.spritedist)
			{
				tmp(big, i, j);
			}
			j++;
		}
		i++;
	}
}

void	spr_raycasting(t_big *big)
{
	int i;

	i = 0;
	sort_spr(big);
	while (i < big->map.num_sprite)
	{
		calculate_transform(i, big);
		calc_drawstartend(big);
		verline_sprites(big);
		i++;
	}
}
