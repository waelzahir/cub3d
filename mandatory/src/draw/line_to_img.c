/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:54:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 06:10:33 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	draw_line_to_img(t_game *game, int x_screen, double x)
{
	double h_scale;
	int					y;

	game->draw_start--;
	h_scale =   (double)game->textures[game->raypole].height / game->lineHeight;
	y = 0;
	if (game->draw_start == -1)
		y = (game->lineHeight - screenHeight) / 2;
	while (++game->draw_start <= game->draw_end)
	{
		pixel_put(&game->img, x_screen, game->draw_start, pixel_get(&game->textures[game->raypole], x, y * h_scale));
		y++;
	}
}
