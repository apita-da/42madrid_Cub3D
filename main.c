/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:01:47 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/12 21:17:09 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_big	big;

	big.save = 0;
	init_map(&big);
	big.mlx.mlx_ptr = mlx_init();
	if (ac == 1 || ac > 3)
		map_error("Wrong number of arguments\n");
	big.map.tfile = ft_strdup(av[1]);
	if (ac == 2)
		readmap(&big, big.map.tfile);
	else if (ac == 3 && ft_strncmp("--save", av[2], 6) == 0)
	{
		if (ft_strlen(av[2]) != 6)
			map_error("Write --save\n");
		readmap(&big, big.map.tfile);
		big.save = 1;
	}
	else
		map_error("Write --save\n");
	big.mlx.win = mlx_new_window(big.mlx.mlx_ptr, big.map.res_x, big.map.res_y,
			"cub3D");
	hooks(&big);
	mlx_loop(big.mlx.mlx_ptr);
	return (0);
}
