/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:20:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 11:02:43 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cube3d.h"

static void	draw_border(t_vars *vars)
{
	int	i;
	int	color;

	color = 180 << 16 | 180 << 8 | 180;
	i = -1;
	while (++i < 216)
	{
		draw_scale_point(vars, new_point_s(0,i), color);
		draw_scale_point(vars, new_point_s(215,i), color);
		draw_scale_point(vars, new_point_s(i,0), color);
		draw_scale_point(vars, new_point_s(i,215), color);
	}
}

static void	check_and_draw(t_vars *vars, int x, int y, int px, int py)
{
	if (is_valid_cords(x, y, vars) && vars->vgame.smap[y][x] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall\
					, px * 24, py * 24);
}

static void	draw_walls(t_vars *vars, int x, int y)
{
	int i;
	int j;

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
	int y;
	int x_iter;
	int dist;

	x = point.x - radius;
	y = point.y - radius;
	while (y < point.y + radius + 1)
	{
		x_iter = x;
		while (x_iter < point.x + radius + 1)
		{
			dist = pow(point.x - x_iter, 2) + pow(point.y - y, 2);
			if (dist >= pow(radius, 2) - 3)
				mlx_pixel_put(vars->mlx, vars->win, x_iter, y, 0x45612);
			x_iter++;
		}
		y++;
	}
	
}

void	draw_2d_map(t_vars *vars)
{
	draw_walls(vars, vars->player.pos_p.x, vars->player.pos_p.y);
	draw_border(vars);
	draw_scale_point(vars, new_point_s((4 * 24) + 12,(4 * 24) + 12)\
		, 255 | 255 << 16| 255<< 8);
	draw_player_as_acircle(vars, new_point_s((4 * 24) + 12,(4 * 24) + 12));
    dda_line_drawing(&vars->player.vec, vars, 4, 4);
}
