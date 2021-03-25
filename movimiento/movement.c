/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 11:23:17 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/05 18:15:08 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement(t_big *big)
{
	move_down(big);
	move_up(big);
	move_right_left(big);
	move_rot_r(big);
	move_rot_l(big);
}
