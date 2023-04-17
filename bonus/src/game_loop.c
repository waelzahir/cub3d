/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:03 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 08:37:19 by ozahir           ###   ########.fr       */
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
		return (-1);
	while (++x_screen < SCREENWIDTH)
	{
		calcul_game(game, player, x_screen);
		draw(game, x_screen);
	}
	draw_img_to_window(vars);
	draw_2d_map(vars);
	return (0);
}
