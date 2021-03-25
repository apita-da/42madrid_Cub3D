/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:36:53 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 11:52:28 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*readmap(t_big *big, char *file)
{
	int	t;

	if ((big->map.fd = open(file, O_RDONLY)) < 0)
		map_error("no valid file\n");
	while ((t = get_next_line(big->map.fd, &big->map.line)) >= 0)
	{
		if (big->check == 8 && *big->map.line != '\0')
			big->check = 9;
		if (big->check == 9)
			get_mapa(big, big->map.line);
		else if (ft_strlen(big->map.line) > 2)
			get_lines(big, big->map.line);
		free(big->map.line);
		if (t == 0)
			break ;
	}
	if (big->check != 9)
		map_error("No enought information\n");
	if (!(big->map.parse))
		map_error("No map\n");
	get_map(big);
	close(big->map.fd);
	return (0);
}

char	*parse_map(t_big *big, char *line)
{
	if (big->map.len < (int)ft_strlen(line))
		big->map.len = (int)ft_strlen(line);
	big->map.parse = str_join(big->map.parse, line);
	big->map.parse = str_join(big->map.parse, "\n");
	return (0);
}

void	check_caracteres(t_big *big)
{
	int	i;

	i = 0;
	while (big->map.parse[i] != '\0')
	{
		if (big->map.parse[i] != '0' &&
			big->map.parse[i] != '1' &&
			big->map.parse[i] != '2' &&
			big->map.parse[i] != 'N' &&
			big->map.parse[i] != 'S' &&
			big->map.parse[i] != 'E' &&
			big->map.parse[i] != 'W' &&
			big->map.parse[i] != ' ' &&
			big->map.parse[i] != '\n')
			map_error("Bad caracter in map\n");
		i++;
	}
}

void	make_square(t_big *big)
{
	int i;

	i = 0;
	while (big->map.mapa[i] != NULL)
	{
		while ((int)ft_strlen(big->map.mapa[i]) < big->map.len)
			big->map.mapa[i] = str_join(big->map.mapa[i], "X");
		change_char(big);
		i++;
		big->map.num_line = i;
	}
}

void	change_char(t_big *big)
{
	int		i;
	int		j;
	char	**mapa;

	mapa = big->map.mapa;
	i = 0;
	while (mapa[i] != NULL)
	{
		j = 0;
		while (mapa[i][j] != '\0')
		{
			if (mapa[i][j] != '1')
				mapa[i][j] = 'X';
			j++;
		}
		i++;
	}
}
