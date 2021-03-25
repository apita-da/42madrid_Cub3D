/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:13:18 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 10:10:34 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_image(t_big *big, int fd)
{
	int		size;
	char	*tmp;

	size = big->map.res_x * (big->map.res_y);
	tmp = big->img.addr;
	write(fd, tmp, (size * 4));
}

void	save_bmp(t_big *big)
{
	int size;
	int	fd;
	int	empty;

	fd = 0;
	size = 0;
	empty = 54;
	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0640);
	size = 54 + (4 * (big->map.res_x * big->map.res_y));
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &empty, 4);
	bmp_header(big, fd);
	bmp_image(big, fd);
	close(fd);
	exit(0);
}

void	bmp_header(t_big *big, int fd)
{
	int header_size;
	int plane;
	int i;
	int	h;

	header_size = 40;
	plane = 1;
	h = -big->map.res_y;
	write(fd, &header_size, 4);
	write(fd, &big->map.res_x, 4);
	write(fd, &h, 4);
	write(fd, &plane, 2);
	write(fd, &big->img.bpp, 2);
	i = 0;
	while (i++ < 32)
	{
		write(fd, "\0", 1);
	}
}
