/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:28:56 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/05 18:12:48 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		error_sprite(t_big *big)
{
	if (!(big->spr.spr_x = malloc(sizeof(int *) * big->map.num_sprite + 1)))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (!(big->spr.spr_y = malloc(sizeof(int *) * big->map.num_sprite + 1)))
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (1);
}

void	parse_sprites(t_big *big)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	while (big->map.mapa[x] != NULL)
	{
		y = 0;
		while (big->map.mapa[x][y] != '\0')
		{
			if (big->map.mapa[x][y] == '2')
			{
				big->spr.spr_x[i] = x + 0.5;
				big->spr.spr_y[i] = y + 0.5;
				i++;
			}
			y++;
		}
		x++;
	}
}

int		get_sprites(t_big *big)
{
	if (error_sprite(big) < 0)
		return (-1);
	parse_sprites(big);
	return (1);
}
