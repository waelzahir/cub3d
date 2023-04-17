/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpWallDist_hight.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:04:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 02:59:12 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calculate_perpwalldist_and_hight(t_game *game)
{
	if (game->side == 0)
		game->perpwalldist = (game->sidedistx - game->deltadistx);
	else
		game->perpwalldist = (game->sidedisty - game->deltadisty);
	game->lineheight = SCREENHEIGHT / game->perpwalldist;
}
