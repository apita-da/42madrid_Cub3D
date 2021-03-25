/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:14:31 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/13 10:38:20 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		openwin(t_big *big)
{
	big->img.img_ptr = mlx_new_image(big->mlx.mlx_ptr, big->map.res_x,
					big->map.res_y);
	big->img.addr = mlx_get_data_addr(big->img.img_ptr, &big->img.bpp,
				&big->img.line_length, &big->img.endian);
}

void		my_mlx_pixel_put(t_big *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x
			* (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int			exitwin(t_big *big)
{
	if (big->map.num_sprite > 0)
		free(big->map.sprite);
	write(1, "el programa se ha cerrado con éxito\n", 37);
	mlx_destroy_window(big->mlx.mlx_ptr, big->mlx.win);
	exit(0);
}

int			game(t_big *big)
{
	openwin(big);
	movement(big);
	raycasting(big);
	if (big->save == 1)
		save_bmp(big);
	mlx_put_image_to_window(big->mlx.mlx_ptr, big->mlx.win,
		big->img.img_ptr, 0, 0);
	return (0);
}

void		hooks(t_big *big)
{
	init_game(big);
	mlx_hook(big->mlx.win, 2, 1L << 0, &key_press, big);
	mlx_hook(big->mlx.win, 3, 1L << 1, &key_release, big);
	mlx_hook(big->mlx.win, 17, 1L << 17, &exitwin, big);
	mlx_loop_hook(big->mlx.mlx_ptr, &game, big);
}
