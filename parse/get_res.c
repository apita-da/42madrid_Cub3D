/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:45:54 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 11:42:56 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_resolution(t_big *big)
{
	big->i++;
	big->i += check_blanks(big->map.line + big->i);
	big->map.res_x = get_params(big);
	big->i += check_blanks(big->map.line + big->i);
	big->map.res_y = get_params(big);
	if (big->map.res_x > 2560 || big->map.res_x < 100)
		big->map.res_x = 2560;
	if (big->map.res_y > 1390 || big->map.res_y < 100)
		big->map.res_y = 1390;
	check_line(big);
}

int		intlen(int i)
{
	int	num;

	num = 0;
	if (i == 0)
		i = 1;
	while (i != 0)
	{
		i = i / 10;
		num++;
	}
	return (num);
}

int		ft_atoi(const char *str)
{
	int		cont;
	int		rest;
	int		sign;

	cont = 0;
	rest = 0;
	sign = 1;
	while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == '\f'
			|| str[cont] == '\v' || str[cont] == '\n' || str[cont] == '\r')
		map_error("error atoi\n");
	while (str[cont] == '+' || str[cont] == '-')
	{
		if (str[cont] == '-')
			map_error("negative number\n");
		cont++;
	}
	while (str[cont] <= '9' && str[cont] >= '0')
	{
		rest = (rest * 10) + (str[cont] - 48);
		cont++;
	}
	return (rest * sign);
}

int		get_params(t_big *big)
{
	int	n;

	n = ft_atoi(&big->map.line[big->i]);
	while (ft_isdigit(big->map.line[big->i]))
		++big->i;
	return (n);
}

void	check_line(t_big *big)
{
	while (big->map.line[big->i])
	{
		if (!(check_blanks(big->map.line + big->i)))
			map_error("No empy end line\n");
		++big->i;
	}
}
