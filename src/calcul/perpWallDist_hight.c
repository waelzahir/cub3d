/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpWallDist_hight.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:04:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 06:05:40 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void calculate_perpWallDist_and_hight(t_game *game)
{
	if (game->side == 0)
		game->perpWallDist = (game->sideDistX - game->deltaDistX);
	else
		game->perpWallDist =  (game->sideDistY - game->deltaDistY);
	game->lineHeight = screenHeight / game->perpWallDist;
}
