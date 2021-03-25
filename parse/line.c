/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:06:27 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 11:07:24 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_lines(t_big *big, char *line)
{
	get_lines0(big, line);
	if (line[0] == 'W' && line[1] == 'E')
	{
		text_west(big, line);
		big->check++;
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		text_east(big, line);
		big->check++;
	}
	else if (line[0] == 'F')
	{
		big->map.flo_colors = get_color(line, big);
		big->check++;
	}
	else if (line[0] == 'C')
	{
		big->map.cel_colors = get_color(line, big);
		big->check++;
	}
	else
		return (0);
	return (1);
}

void		get_lines0(t_big *big, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
	{
		get_resolution(big);
		big->check++;
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		text_north(big, line);
		big->check++;
	}
	else if (line[0] == 'S')
	{
		if (line[1] == 'O')
		{
			text_south(big, line);
			big->check++;
		}
		else
		{
			text_sprite(big, line);
			big->check++;
		}
	}
}

int			get_mapa(t_big *big, char *line)
{
	if (*line == '\0')
		big->c_map = 1;
	if (big->c_map == 1 && (*line == '0' || *line == '1' || *line == '2'))
		map_error("Broken map\n");
	parse_map(big, line);
	return (1);
}
