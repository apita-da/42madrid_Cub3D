/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:25:35 by apita-da          #+#    #+#             */
/*   Updated: 2021/02/20 15:47:33 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_line(int fd, char **str, char **line, int rd)
{
	char		*tmp;
	char		*nl;

	if (!str[fd] && !rd)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((nl = ft_strchr(str[fd], '\n')))
	{
		*nl = '\0';
		*line = ft_strdup(str[fd]);
		tmp = ft_strdup(++nl);
		free(str[fd]);
		str[fd] = tmp;
		return (1);
	}
	else
	{
		*line = str[fd];
		str[fd] = NULL;
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*str[4096];
	int			rd;
	char		*temp;

	if (!line || fd < 0 || fd > 4095 || (rd = read(fd, buff, 0)) == -1
			|| BUFFER_SIZE < 1)
		return (-1);
	while ((rd = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rd] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup("");
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (rd < 0)
		return (-1);
	rd = get_line(fd, str, line, rd);
	return (rd);
}

char			*ft_strchr(const char *str, int c)
{
	unsigned int	cont;

	cont = 0;
	while (str[cont] != c)
	{
		if (str[cont] == '\0')
			return (NULL);
		cont++;
	}
	return ((char *)&str[cont]);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	int			cont;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char *))))
		return (NULL);
	cont = 0;
	while (*s1)
	{
		s3[cont] = *s1;
		s1++;
		cont++;
	}
	while (*s2)
	{
		s3[cont] = *s2;
		s2++;
		cont++;
	}
	s3[cont] = '\0';
	return (s3);
}

char			*ft_strdup(const char *s1)
{
	char	*s2;
	int		cont;
	int		len;

	len = ft_strlen(s1);
	if (!(s2 = malloc(sizeof(char) * len + 1)))
		return (NULL);
	cont = 0;
	while (s1[cont] != '\0')
	{
		s2[cont] = s1[cont];
		cont++;
	}
	s2[cont] = '\0';
	return (s2);
}
