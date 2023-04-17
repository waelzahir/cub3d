/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:43:24 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 13:25:14 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	dda_line_drawing(t_vector *vec, t_vars *vars, int x0, int y0)
{
	double	x;
	double	y;
	double	ix;
	double	iy;
	int		i;

	ix = vec->dx;
	iy = vec->dy;
	x = (x0 * 24) + 12;
	y = (y0 * 24) + 12;
	i = -1;
	while (++i < RADIUS)
	{
		mlx_pixel_put(vars->mlx, vars->win, round(x), round(y), COLORDRAW);
		x += ix;
		y += iy;
	}
}
