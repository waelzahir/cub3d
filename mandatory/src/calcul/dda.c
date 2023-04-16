/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 09:16:34 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void dda_calcul(t_game *game)
{
	while (!game->hit)
	{
		if (game->sidedistx < game->sidedisty)
		{
			game->sidedistx += game->deltadistx;
			game->mapx += game->stepX;
			game->side = 0;
		}
		else
		{
			game->sidedisty += game->deltadisty;
			game->mapy += game->stepY;
			game->side = 1;
		}
		if (game->smap[game->mapy][game->mapx] == '1')
			game->hit = 1;
	}
}
