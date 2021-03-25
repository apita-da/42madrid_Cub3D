/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 10:27:47 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/12 21:17:38 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_textura(t_big *big, int i)
{
	if (big->ray.side == 0)
		big->ray.wall_x = big->map.pos_y +
			(big->ray.perpwalldist * big->ray.raydir_y);
	else
		big->ray.wall_x = big->map.pos_x +
			(big->ray.perpwalldist * big->ray.raydir_x);
	big->ray.wall_x -= floor((big->ray.wall_x));
	if (big->ray.side == 0 && big->ray.raydir_x > 0)
		big->ray.wall = 0;
	else if (big->ray.side == 0 && big->ray.raydir_x < 0)
		big->ray.wall = 1;
	else if (big->ray.side == 1 && big->ray.raydir_y > 0)
		big->ray.wall = 2;
	else if (big->ray.side == 1 && big->ray.raydir_y < 0)
		big->ray.wall = 3;
	big->ray.tex_x = (int)(big->ray.wall_x *
		(double)(big->tex[big->ray.wall].width) - 1);
	big->ray.step = 1.0 * big->tex[big->ray.wall].height / big->ray.lineheight;
	big->ray.tex_pos = (big->ray.drawstart - (big->map.res_y / 2) +
		(big->ray.lineheight / 2)) * big->ray.step;
	big->ray.tex_y = (i - (-big->ray.lineheight / 2 + big->map.res_y / 2)) /
		(big->ray.lineheight / (double)big->tex[big->ray.wall].height);
	big->ray.tex_pos += big->ray.step;
	big->ray.tex_color = big->tex[big->ray.wall].data
		[big->tex[big->ray.wall].height * big->ray.tex_y + big->ray.tex_x];
}

void	get_texture(t_big *big)
{
	if (!(big->tex[0].img_ptr = mlx_xpm_file_to_image(big->mlx.mlx_ptr,
		big->map.east, &big->tex[0].width, &big->tex[0].height)))
		map_error("Wrong East texture path\n");
	big->tex[0].data = (int*)mlx_get_data_addr(big->tex[0].img_ptr,
		&big->tex[0].bpp, &big->tex[0].line_length, &big->tex[0].endian);
	if (!(big->tex[1].img_ptr = mlx_xpm_file_to_image(big->mlx.mlx_ptr,
		big->map.west, &big->tex[1].width, &big->tex[1].height)))
		map_error("Wrong West texture path\n");
	big->tex[1].data = (int*)mlx_get_data_addr(big->tex[1].img_ptr,
		&big->tex[1].bpp, &big->tex[1].line_length, &big->tex[1].endian);
	if (!(big->tex[2].img_ptr = mlx_xpm_file_to_image(big->mlx.mlx_ptr,
		big->map.south, &big->tex[2].width, &big->tex[2].height)))
		map_error("Wrong South texture path\n");
	big->tex[2].data = (int*)mlx_get_data_addr(big->tex[2].img_ptr,
		&big->tex[2].bpp, &big->tex[2].line_length, &big->tex[2].endian);
	if (!(big->tex[3].img_ptr = mlx_xpm_file_to_image(big->mlx.mlx_ptr,
		big->map.north, &big->tex[3].width, &big->tex[3].height)))
		map_error("Wrong North texture path\n");
	big->tex[3].data = (int*)mlx_get_data_addr(big->tex[3].img_ptr,
		&big->tex[3].bpp, &big->tex[3].line_length, &big->tex[3].endian);
}
