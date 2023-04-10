/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_delta.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 06:01:18 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void calculate_delta_x_and_y(t_game *game)
{
	if (!game->rayDirX)
		game->deltaDistX = 1e30;
	else
		game->deltaDistX = ft_dabs(1 / game->rayDirX);
	if (!game->rayDirY)
		game->deltaDistY = 1e30;
	else
		game->deltaDistY = ft_dabs(1 / game->rayDirY);
	game->perpWallDist = 0;
	game->hit = 0;
}
