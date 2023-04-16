/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:42:16 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 05:52:51 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cube3d.h"



double abss(double n)
{
	if (n > 0)
		return (n);
	return (n * (-1));
}

static int get_steps(double dx, double dy)
{
	if (abss(dx) > abss(dy))
		return (abss(dx));
	return round(abss(dy));
}

int is_valid(int x, int y)
{
	if (x < screenWidth && x >= 0 && y < screenHeight && y >= 0)
		return 1;
	return 0;
}
/// @brief 
/// @param vec 
/// @param vars 
void dda_line_drawing(t_vector *vec, t_vars *vars, int x0, int y0)
{
    (void)vars, (void)vec;
	double steps;
	double x;
	double y;
	double ix;
	double iy;

	steps = get_steps(vec->dx, vec->dy);
	if (steps == 0)
		steps = 1;
	// ix = (vec->dx * 25) / steps;
	// iy = (vec->dy * 24) / steps;
	ix = (vec->dx / steps);
	iy = (vec->dy / steps);

	x = (x0 * 24) + 12;
	y = (y0 * 24) + 12;
    int i = -1;
	while (is_valid(round(x), round(y)) && ++i < radius)
	{
        // draw_scale_point(vars, new_point_s(round(x), round(y)), 255 << 8 | 255 << 16);
		mlx_pixel_put(vars->mlx, vars->win, round(x), round(y), 255 << 8 | 255 << 16);
		x += ix;
		y += iy;
		if (vars->vgame.smap[(int)round(y) / (screenHeight * vars->vgame.map_hight)][(int)(round(x) / (screenWidth * vars->vgame.map_width))] == 1)
			break;
	}
    // draw_scale_point(vars, new_point_s(x, y), 255 << 8 | 255);
}

int is_valid2(int x , int y, t_vars *vars)
{
	if  (x >= vars->vgame.map_width|| y >= vars->vgame.map_hight)
		return 0;
	if  (x < 0 || y < 0)
		return 0;
	return 1;
}
void	draw_player_as_acircle(t_vars	*vars, t_point point)
{
	int	x;
	int y;
	int x_iter;
	int dist;

	x = point.x - radius ;
	y = point.y - radius  ;
	while (y < point.y + radius + 1)
	{
		x_iter = x;
		while (x_iter < point.x + radius + 1)
		{
			dist = pow(point.x - x_iter, 2) + pow(point.y - y, 2);
			
			if (dist  >= pow(radius, 2) - 3)
				mlx_pixel_put(vars->mlx, vars->win, x_iter, y, 0x45612);
			x_iter++;
		}
		y++;
	}
	
}
void draw_wall(t_vars *vars)
{
	int i;
	int j;

	
	i = 0;
	while (i < 216)
	{
		j = 0;
		while (j < 216 && (i == 0 || i == 215))
		{
			draw_scale_point(vars, new_point_s(j,i), 255 << 16| 255<< 8);
			j++;
		}
		if ((i != 0 && i != 215))
			draw_scale_point(vars, new_point_s(0,i), 255 | 255 << 16| 255<< 8);
		if ((i != 0 && i != 215))
			draw_scale_point(vars, new_point_s(215,i), 255 | 255 << 16| 255<< 8);
		i++;
	}
	int x;
	int y;

	
	i = 1;
	x = vars->player.pos_p.x;
	y = vars->player.pos_p.y;
	while (i < 5)
	{
		j = 0;
		while (j < 4)
		{
			if (is_valid2(x + j, y + i, vars) && vars->vgame.smap[y + i][x + j] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall, (4 + j) * 24, (4 + i) * 24);
			if (is_valid2(x + j, y - i, vars) && vars->vgame.smap[y - i][x + j] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall, (4 + j) * 24, (4 - i) * 24);
			if (is_valid2(x - j, y + i, vars) && vars->vgame.smap[y + i][x - j] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall, (4 - j) * 24, (4 + i) * 24);
			if (is_valid2(x - j, y - i, vars) && vars->vgame.smap[y - i][x - j] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall, (4 - j) * 24, (4 - i) * 24);
			if (is_valid2(x , y - i, vars) && vars->vgame.smap[y - i][x] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall, (4 ) * 24, (4 - i) * 24);
			if (is_valid2(x , y + i, vars) && vars->vgame.smap[y + i][x] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall, (4 ) * 24, (4 + i) * 24);
			if (is_valid2(x - j, y, vars) && vars->vgame.smap[y][x - j] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall, (4 - j) * 24, (4) * 24);
			if (is_valid2(x + j, y, vars) && vars->vgame.smap[y][x + j] == '1')
				mlx_put_image_to_window(vars->mlx,vars->win, vars->imgs.wall, (4 + j ) * 24, (4) * 24);
			j++;
		}
		i++;
	}
	draw_scale_point(vars, new_point_s((4 * 24) + 12,(4 * 24) + 12), 255 | 255 << 16| 255<< 8);

	draw_player_as_acircle(vars, new_point_s((4 * 24) + 12,(4 * 24) + 12));










	
	// draw_scale_point(vars, new_point_s(4, 4), 255 << 16| 255);
    dda_line_drawing(&vars->player.vec, vars, 4, 4);	
}

void	print_game_infos(t_game *game, t_pl *player, int x_screen, int max_x)
{
	if (x_screen < 3 || (x_screen == (max_x / 2)) || max_x == x_screen)
	{
		if (max_x == x_screen)
			printf("\n==========Max========= \n");
		else if (x_screen == (max_x / 2))
			printf("\n========Middle======== \n");
		else
			printf("\n=========start======== \n");
		printf("camera          : %.2f\n\n", game->cameraX);
		printf("player vector x : %.2f\n", player->vec.dx);
		printf("player vector y : %.2f\n\n", player->vec.dy);
		printf("game->rayDirX   : %.2f\n", game->rayDirX);
		printf("game->rayDirY   : %.2f\n\n", game->rayDirY);
		printf("====================== \n");
		printf("game->deltaDistX : %.2f\n", game->deltaDistX);
		printf("game->deltaDistY : %.2f\n", game->deltaDistY);
		printf("game->sideDistX : %.2f\n", game->sideDistX);
		printf("game->sideDistY : %.2f\n", game->sideDistY);
		printf("====================== \n");
		printf("x_screen        : %d\n", x_screen);
		printf("perpWallDist    : %f\n", game->perpWallDist);
		printf("side            : %d\n", game->side);
		printf("====================== \n");
		print_magnitude(game->rayDirX, game->rayDirY);
		printf("====================== \n\n\n");
	}
}

void	print_magnitude(double dx, double dy)
{
	printf("magnitude       : %.4f\n", sqrt(pow(dy, 2) + pow(dx, 2)));
}

void draw_scale_point(t_vars *vars, t_point _point, int color)
{
    t_point point = _point;

	mlx_pixel_put(vars->mlx, vars->win, point.x , point.y, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x , point.y - 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1 , point.y - 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1 , point.y - 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x , point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1 , point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1 , point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1 , point.y, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1 , point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1 , point.y - 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1 , point.y, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1 , point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1 , point.y - 1, color);
}