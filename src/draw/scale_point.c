/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:35:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 09:36:23 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

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
