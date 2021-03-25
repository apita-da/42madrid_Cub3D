/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:25:43 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/13 21:38:36 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			rgb_int(int red, int green, int blue)
{
	int		rgb;

	if (red > 255 || green > 255 || blue > 255)
		map_error("large colors number\n");
	if (red < 0 || green < 0 || blue < 0)
		map_error("small colors number\n");
	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

char		check_blanks(char *strs)
{
	int		i;

	i = 0;
	while (strs[i] == ' ')
	{
		i++;
	}
	return (i);
}

char		*str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int			cont_spr(char *parse)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (parse[i] != '\0')
	{
		if (parse[i] == '2')
			j++;
		i++;
	}
	return (j);
}
