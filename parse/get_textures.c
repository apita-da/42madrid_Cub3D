/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:12:04 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/12 21:16:10 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	text_north(t_big *big, char *line)
{
	if (line[2] != ' ')
		map_error("in north's path\n");
	line = line + 3;
	line = line + check_blanks(line);
	big->map.north = ft_strdup(line);
	return (0);
}

char	text_south(t_big *big, char *line)
{
	if (line[2] != ' ')
		map_error("in south's path\n");
	line = line + 3;
	line = line + check_blanks(line);
	big->map.south = ft_strdup(line);
	return (0);
}

char	text_west(t_big *big, char *line)
{
	if (line[2] != ' ')
		map_error("in west's path\n");
	line = line + 3;
	line = line + check_blanks(line);
	big->map.west = ft_strdup(line);
	return (0);
}

char	text_east(t_big *big, char *line)
{
	if (line[2] != ' ')
		map_error("in east's path\n");
	line = line + 3;
	line = line + check_blanks(line);
	big->map.east = ft_strdup(line);
	return (0);
}

char	text_sprite(t_big *big, char *line)
{
	if (line[1] != ' ')
		map_error("in sprites's path\n");
	line = line + 2;
	line = line + check_blanks(line);
	big->map.sprite = ft_strdup(line);
	return (0);
}
