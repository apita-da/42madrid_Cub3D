/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:16:30 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/12 21:17:29 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		write_sprites(t_big *big)
{
	int		y;
	int		d;

	d = 0;
	y = big->spr.drawstarty;
	while (y < big->spr.drawendy)
	{
		d = (y) * 256 - big->map.res_y * 128 + big->spr.spr_he * 128;
		big->spr.tex_y = ((d * big->tex[big->ray.wall].height) /
			big->spr.spr_he) / 256;
		big->spr.color = big->spr.data[(big->spr.spr_size / 4) *
			big->spr.tex_y + big->spr.tex_x];
		if ((big->spr.color & BLACK) != 0)
			big->img.addr[y * big->map.res_x + big->spr.stripe] =
				big->spr.color;
		if (big->spr.color != 0)
			my_mlx_pixel_put(big, big->spr.stripe, y, big->spr.color);
		y++;
	}
}

void		verline_sprites(t_big *big)
{
	big->spr.stripe = big->spr.drawstartx;
	while (big->spr.stripe < big->spr.drawendx)
	{
		big->spr.tex_x = (int)((256 * (big->spr.stripe - ((-big->spr.spr_wi / 2)
			+ big->spr.spritescreenx))) * big->tex[big->ray.wall].width /
			big->spr.spr_wi) / 256;
		if (big->spr.transformy > 0 && big->spr.stripe > 0
			&& big->spr.stripe < big->map.res_x
			&& big->spr.transformy < big->spr.zbuffer[big->spr.stripe])
		{
			write_sprites(big);
		}
		big->spr.stripe++;
	}
}

void		get_spr_tex(t_big *big)
{
	if (!(big->spr.spr_ptr = mlx_xpm_file_to_image(big->mlx.mlx_ptr,
		big->map.sprite, &big->spr.spr_wi, &big->spr.spr_he)))
		map_error("Wrong Sprite texture path\n");
	big->spr.data = (int*)mlx_get_data_addr(big->spr.spr_ptr,
		&big->spr.bpp, &big->spr.spr_size, &big->spr.endian);
}
