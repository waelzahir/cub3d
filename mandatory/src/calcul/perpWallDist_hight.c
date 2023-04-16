/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpWallDist_hight.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:04:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 09:16:12 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void calculate_perpwalldist_and_hight(t_game *game)
{
	if (game->side == 0)
		game->perpwalldist = (game->sidedistx - game->deltadistx);
	else
		game->perpwalldist =  (game->sidedisty - game->deltadisty);
	game->lineHeight = screenHeight / game->perpwalldist;
}
