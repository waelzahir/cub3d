/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:44:25 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 06:03:45 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calcul_game(t_game *game, t_pl *player, int x_screen)
{
		calculate_ray_position_and_direction(game, player, x_screen);
		set_map_cords_with_player(game, player);
		calculate_delta_x_and_y(game);
		calculate_steps_init_side_dist(game, player);
		dda_calcul(game);
		calculate_perpWallDist_and_hight(game);
		calculate_lowest_and_highest_pixel(game);
		get_ray_polarity(game);
		get_x_textures(game, player);
}
