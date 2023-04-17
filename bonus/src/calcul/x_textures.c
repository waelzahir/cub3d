/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:32:48 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 09:45:43 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	get_x_textures(t_game *game, t_pl *player)
{
	double	wallx;
	int		x_text;

	if (game->side == 1)
		wallx = player->pos_p.x + game->perpwalldist * game->raydirx;
	else
		wallx = player->pos_p.y + game->perpwalldist * game->raydiry;
	wallx = wallx - (int)(wallx);
	x_text = wallx * (double)game->textures[game->raypole].width;
	if (game->raypole == SOUTH || game->raypole == WEST)
		x_text = game->textures[game->raypole].width - x_text - 1;
	game->x_tex = x_text;
}
