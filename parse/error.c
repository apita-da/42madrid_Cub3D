/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:38:29 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/13 12:12:04 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_error(char *error)
{
	write(1, "Error:\n", 7);
	write(1, error, ft_strlen(error));
	exit(0);
}

int		error(char *error)
{
	write(1, "Error:\n", 7);
	write(1, error, ft_strlen(error));
	exit(0);
	return (-1);
}
