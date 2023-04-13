/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:03 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/13 01:51:20 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
 
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void colorize_floor_and_ceiling(t_game	*game, int x)
{
	int st;
	int en;

	st = -1;
	en = game->draw_end - 1;
	while (++st < game->draw_start)
		pixel_put(&game->img, x, st, game->color[0]);
	while (++en < screenHeight - 1)
		pixel_put(&game->img, x, en, game->color[1]);
}
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
		colorize_floor_and_ceiling(game, x_screen);
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
