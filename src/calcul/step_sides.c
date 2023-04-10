/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_step_sides.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 06:00:49 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calculate_steps_init_side_dist(t_game *_ga, t_pl *player)
{
	if (_ga->rayDirX < 0)
    {
        _ga->stepX = -1;
        _ga->sideDistX = (player->pos_p.x - _ga->mapX) * _ga->deltaDistX;
    }
	else
	{
		_ga->stepX = 1;
		_ga->sideDistX = (_ga->mapX + 1.0 - player->pos_p.x) * _ga->deltaDistX;
	}
	if (_ga->rayDirY < 0)
	{
		_ga->stepY = -1;
		_ga->sideDistY = (player->pos_p.y - _ga->mapY) * _ga->deltaDistY;
	}
	else
	{
		_ga->stepY = 1;
		_ga->sideDistY = (_ga->mapY + 1.0 - player->pos_p.y) * _ga->deltaDistY;
	}
}
