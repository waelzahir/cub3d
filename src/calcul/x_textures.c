/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:32:48 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 06:06:49 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cube3d.h"


void	get_x_textures(t_game *game, t_pl *player)
{
	double	wallx;
	int		x_text;

	if (game->side == 1)
		wallx = player->pos_p.x + game->perpWallDist * game->rayDirX;
	else
		wallx = player->pos_p.y + game->perpWallDist * game->rayDirY;
	wallx = wallx - (int)(wallx);
	
	x_text = wallx * (double)game->textures[game->raypole].width;
	if (game->raypole == NORTH || game->raypole == WEST)
		x_text =game->textures[game->raypole].width - x_text - 1;
	game->x_tex = x_text;
}