/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:42:16 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 06:35:09 by tel-mouh         ###   ########.fr       */
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
void dda_line_drawing(t_vector *vec, t_vars *vars)
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
	// ix = (vec->dx * 24) / steps;
	// iy = (vec->dy * 24) / steps;
	ix = (vec->dx / steps);
	iy = (vec->dy / steps);

	x = vars->player.pos_p.x * 24;
	y = vars->player.pos_p.y * 24;
    int i = -1;
	while (is_valid(round(x), round(y)) && ++i < 30)
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

void draw_wall(t_vars *vars)
{
	int i;
	int j;

	i = -1;
	(void)vars;
	while (++i < vars->vgame.map_hight)
	{
		j = -1;
		while (++j < vars->vgame.map_width)
		{
			if (vars->vgame.smap[i][j] != '0')
			    mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.wall, j * 24 , i * 24);
                // printf("hello\n");
		}
	}
    dda_line_drawing(&vars->player.vec, vars);	
}

void	print_game_infos(t_game *game, t_pl *player, int x_screen, int max_x)
{
	if (x_screen < 3 || (x_screen == (max_x / 2)) || max_x == x_screen)
	{
		if (max_x == x_screen)
			printf("\n==========Max========= \n");
		else if ((x_screen == (max_x / 2)))
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

    _point.x *= 24;			
    _point.y *= 24;
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