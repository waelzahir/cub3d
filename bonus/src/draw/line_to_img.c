/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:54:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 11:24:58 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	draw_line_to_img(t_game *game, int x_screen, double x)
{
	double	h_scale;
	int		y;

	game->draw_start--;
	h_scale = (double)(game->textures[game->raypole].height) / game->lineheight;
	y = 0;
	if (game->draw_start == -1)
		y = (game->lineheight - SCREENHEIGHT) / 2;
	while (++game->draw_start <= game->draw_end)
	{
		pixel_put(&game->img, x_screen, game->draw_start,
			pixel_get(&game->textures[game->raypole], x, y * h_scale));
		y++;
	}
}
