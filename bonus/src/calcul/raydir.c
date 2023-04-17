/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raydir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 06:12:27 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calculate_ray_pos_and_dir(t_game *game, t_pl *player, int x_screen)
{
	game->camerax = 2 * x_screen / (double)SCREENWIDTH - 1;
	game->raydirx = player->vec.dx + player->plane.x * game->camerax;
	game->raydiry = player->vec.dy + player->plane.y * game->camerax;
}
