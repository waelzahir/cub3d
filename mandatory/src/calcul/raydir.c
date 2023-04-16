/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raydir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 09:15:15 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calculate_ray_position_and_direction(t_game *game, t_pl *player, int x_screen)
{
	game->camerax = 2 * x_screen / (double)screenWidth - 1;
	game->raydirx = player->vec.dx + player->plane.x * game->camerax;
	game->raydiry = player->vec.dy + player->plane.y * game->camerax;
}
