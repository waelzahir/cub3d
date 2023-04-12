/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:03 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/12 07:35:50 by ozahir           ###   ########.fr       */
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
		// print_game_infos(game, player, x_screen, 3);
	}
	draw_img_to_window(vars);
	draw_wall(vars);
	return 0;
}

int	render(t_vars	*vars)
{
	if (vars->press.hor != -1)
		move_horizontal(vars);
	if (vars->press.ver != -1)
		move_vertical(vars);
	if (vars->press.rot != -1)
		move_rotation(vars);
	if (vars->press.hor != -1 || vars->press.ver != -1 || vars->press.rot != -1)
		game_loop(vars);
	return (0);
}
