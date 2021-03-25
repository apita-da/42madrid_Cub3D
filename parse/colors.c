/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:44:38 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 11:23:34 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_comas(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 44)
			j++;
		if (str[i] == 44 && str[i + 1] == 44)
			map_error("wrong number of comas");
		i++;
	}
	return (j);
}

void	check_chars(char *line)
{
	line += 2;
	while (*line != '\0')
	{
		if (*line != ' ' && *line != ',' && ft_isdigit(*line) == 0)
			map_error("Invalid character in color line\n");
		line++;
	}
}

int		valid_coma(char *line, int i)
{
	if (line[i] != ',')
		map_error("check coma positon\n");
	return (1);
}

int		get_color(char *line, t_big *big)
{
	int i;

	i = 2;
	big->color.r = -1;
	big->color.g = -1;
	big->color.b = -1;
	check_chars(line);
	check_comas(line) != 2 ? map_error("check comas in color line\n") : 1;
	i = i + check_blanks(&line[i]);
	ft_isdigit(line[i]) ? big->color.r = ft_atoi(&line[i]) : map_error("R\n");
	i = i + intlen(big->color.r);
	i = i + check_blanks(&line[i]);
	i += valid_coma(line, i);
	i = i + check_blanks(&line[i]);
	ft_isdigit(line[i]) ? big->color.g = ft_atoi(&line[i]) : map_error("G\n");
	i = i + intlen(big->color.g);
	i = i + check_blanks(&line[i]);
	i += valid_coma(line, i);
	i = i + check_blanks(&line[i]);
	ft_isdigit(line[i]) ? big->color.b = ft_atoi(&line[i]) : map_error("B\n");
	i = i + intlen(big->color.b);
	i = i + check_blanks(&line[i]);
	line[i] != '\0' ? map_error("check color's end line\n") : 1;
	return (rgb_int(big->color.r, big->color.g, big->color.b));
}
