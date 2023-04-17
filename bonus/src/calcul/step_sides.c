/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_sides.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 06:07:02 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calculate_steps_init_side_dist(t_game *_ga, t_pl *player)
{
	if (_ga->raydirx < 0)
	{
		_ga->stepx = -1;
		_ga->sidedistx = (player->pos_p.x - _ga->mapx) * _ga->deltadistx;
	}
	else
	{
		_ga->stepx = 1;
		_ga->sidedistx = (_ga->mapx + 1.0 - player->pos_p.x) * _ga->deltadistx;
	}
	if (_ga->raydiry < 0)
	{
		_ga->stepy = -1;
		_ga->sidedisty = (player->pos_p.y - _ga->mapy) * _ga->deltadisty;
	}
	else
	{
		_ga->stepy = 1;
		_ga->sidedisty = (_ga->mapy + 1.0 - player->pos_p.y) * _ga->deltadisty;
	}
}
