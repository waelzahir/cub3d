/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:03 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 17:24:57 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"


int	game_loop(t_vars *vars)
{
	t_game	*game;
	t_pl	*player;
	int		x_screen;

	x_screen = -1;
	game = &vars->vgame;
	player = &vars->player;
	if (init_image_to_draw(vars))
		return -1;
	while (++x_screen < screenWidth)
	{
		calcul_game(game, player, x_screen);
		draw_line_to_img(game, x_screen);
		print_game_infos(game, player, x_screen, 3);
	}
	draw_img_to_window(vars);
	draw_wall(vars);
	return 0;
}