/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_raydir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 05:58:47 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calculate_ray_position_and_direction(t_game *game, t_pl *player, int x_screen)
{
	game->cameraX = 2 * x_screen / (double)screenWidth - 1;
	game->rayDirX = player->vec.dx + player->plane.x * game->cameraX;
	game->rayDirY = player->vec.dy + player->plane.y * game->cameraX;
}
