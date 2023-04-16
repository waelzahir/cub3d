/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:39:03 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 05:25:34 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
 
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	pixel_get(t_data *data, int x, int y)
{
	char	*dst;
 
	if (y >= data->height)
		y = data->height - 1;
	if (x >= data->height)
		x = data->width - 1;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
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
		colorize_floor_and_ceiling(game, x_screen);
		draw_line_to_img(game, x_screen, 0);
		// print_game_infos(game, player, x_screen, 3);
	}
	printf("ray_pol  %d\n", game->raypole);
	printf("side  %d\n", game->side);
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
