/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:20:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 11:39:05 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

static void	draw_border(t_vars *vars)
{
	int	i;

	i = -1;
	while (++i < 216)
	{
		draw_scale_point(vars, new_point_s(0, i), COLORRAY);
		draw_scale_point(vars, new_point_s(215, i), COLORRAY);
		draw_scale_point(vars, new_point_s(i, 0), COLORRAY);
		draw_scale_point(vars, new_point_s(i, 215), COLORRAY);
	}
}

static void	check_and_draw(t_vars *vars, int x, int y, int px, int py)
{
	if (is_valid_cords(x, y, vars) && vars->vgame.smap[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.wall,
			px * 24, py * 24);
}

static void	draw_walls(t_vars *vars, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			check_and_draw(vars, x + j, y + i, 4 + j, 4 + i);
			check_and_draw(vars, x + j, y - i, 4 + j, 4 - i);
			check_and_draw(vars, x - j, y + i, 4 - j, 4 + i);
			check_and_draw(vars, x - j, y - i, 4 - j, 4 - i);
			check_and_draw(vars, x, y - i, 4, 4 - i);
			check_and_draw(vars, x, y + i, 4, 4 + i);
			check_and_draw(vars, x - j, y, 4 - j, 4);
			check_and_draw(vars, x + j, y, 4 + j, 4);
			j++;
		}
		i++;
	}
}

static void	draw_player_as_acircle(t_vars	*vars, t_point point)
{
	int	x;
	int	y;
	int	x_iter;
	int	dist;

	x = point.x - RADIUS;
	y = point.y - RADIUS;
	while (y < point.y + RADIUS + 1)
	{
		x_iter = x;
		while (x_iter < point.x + RADIUS + 1)
		{
			dist = pow(point.x - x_iter, 2) + pow(point.y - y, 2);
			if (dist >= pow(RADIUS, 2) - 3)
				mlx_pixel_put(vars->mlx, vars->win, x_iter, y, vars->vgame.color[1]);
			x_iter++;
		}
		y++;
	}
}

void	draw_2d_map(t_vars *vars)
{
	draw_walls(vars, vars->player.pos_p.x, vars->player.pos_p.y);
	draw_border(vars);
	draw_scale_point(vars, new_point_s((4 * 24) + 12, (4 * 24) + 12),
		0xffffff);
	draw_player_as_acircle(vars, new_point_s((4 * 24) + 12, (4 * 24) + 12));
	dda_line_drawing(&vars->player.vec, vars, 4, 4);
}
