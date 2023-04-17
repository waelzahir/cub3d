/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:43:24 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 06:15:14 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

static	int	get_steps(double dx, double dy)
{
	if (ft_dabs(dx) > ft_dabs(dy))
		return (ft_dabs(dx));
	return (ft_dabs(dy));
}

static	int	is_valid(int x, int y)
{
	if (x < SCREENWIDTH && x >= 0 && y < SCREENHEIGHT && y >= 0)
		return (1);
	return (0);
}

/// @brief 
/// @param vec 
/// @param vars 
void	dda_line_drawing(t_vector *vec, t_vars *vars, int x0, int y0)
{
	double	steps;
	double	x;
	double	y;
	double	ix;
	double	iy;

	steps = get_steps(vec->dx, vec->dy);
	if (steps == 0)
		steps = 1;
	ix = (vec->dx / steps);
	iy = (vec->dy / steps);
	x = (x0 * 24) + 12;
	y = (y0 * 24) + 12;
    int i = -1;
	while (is_valid(round(x), round(y)) && ++i < radius)
	{
		mlx_pixel_put(vars->mlx, vars->win, round(x), round(y), 255 << 8 | 255 << 16);
		x += ix;
		y += iy;
		if (vars->vgame.smap[(int)round(y) / (SCREENHEIGHT * vars->vgame.map_hight)]
			[(int)(round(x) / (SCREENWIDTH * vars->vgame.map_width))] == 1)
			break;
	}
}