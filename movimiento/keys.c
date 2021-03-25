/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:38:33 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/12 21:37:05 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int keycode, t_big *big)
{
	if (keycode == 53)
	{
		if (big->map.num_sprite > 0)
			free(big->map.sprite);
		write(1, "el programa se ha cerrado con éxito\n", 37);
		mlx_destroy_window(big->mlx.mlx_ptr, big->mlx.win);
		exit(0);
	}
	if (keycode == KEY_UP_W || keycode == KEY_UP_ARR)
		big->mov.key_w = 1;
	else if (keycode == KEY_DOWN_S || keycode == KEY_DOWN_ARR)
		big->mov.key_s = 1;
	else if (keycode == KEY_LEFT_A)
		big->mov.key_a = 1;
	else if (keycode == KEY_RIGHT_D)
		big->mov.key_d = 1;
	else if (keycode == KEY_MOV_LEFT_Q || keycode == KEY_LEFT_ARR)
		big->mov.key_q = 1;
	else if (keycode == KEY_MOV_RIGHT_E || keycode == KEY_RIGHT_ARR)
		big->mov.key_e = 1;
	return (0);
}

int		key_release(int keycode, t_big *big)
{
	if (keycode == KEY_UP_W || keycode == KEY_UP_ARR)
		big->mov.key_w = 0;
	else if (keycode == KEY_DOWN_S || keycode == KEY_DOWN_ARR)
		big->mov.key_s = 0;
	else if (keycode == KEY_LEFT_A)
		big->mov.key_a = 0;
	else if (keycode == KEY_RIGHT_D)
		big->mov.key_d = 0;
	else if (keycode == KEY_MOV_LEFT_Q || keycode == KEY_LEFT_ARR)
		big->mov.key_q = 0;
	else if (keycode == KEY_MOV_RIGHT_E || keycode == KEY_RIGHT_ARR)
		big->mov.key_e = 0;
	else if (keycode == KEY_RUN)
		big->mov.key_x = 0;
	else if (keycode == KEY_SLOW)
		big->mov.key_z = 0;
	return (0);
}
