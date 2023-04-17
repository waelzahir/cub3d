/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:35:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 06:14:06 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	draw_scale_point(t_vars *vars, t_point _point, int color)
{
	t_point	point;

	point = _point;
	mlx_pixel_put(vars->mlx, vars->win, point.x, point.y, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x, point.y - 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1, point.y - 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1, point.y - 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x, point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1, point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1, point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1, point.y, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1, point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x + 1, point.y - 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1, point.y, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1, point.y + 1, color);
	mlx_pixel_put(vars->mlx, vars->win, point.x - 1, point.y - 1, color);
}
