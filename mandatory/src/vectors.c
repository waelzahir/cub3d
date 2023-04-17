/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:01:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 02:43:55 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	rotate_vector(t_vars *vars, t_vector *a, double teta)
{
	t_vector	sum;

	if (teta == 1)
	{
		sum.dx = (a->dx * vars->player.vec.prec.ang_cos)
			- (a->dy * vars->player.vec.prec.ang_sin);
		sum.dy = (a->dx) * vars->player.vec.prec.ang_sin
			+ (a->dy) * vars->player.vec.prec.ang_cos;
		double oldPlaneX = vars->player.plane.x;
      	vars->player.plane.x = vars->player.plane.x * vars->player.vec.prec.ang_cos
			- vars->player.plane.y * vars->player.vec.prec.ang_sin;
      	vars->player.plane.y = oldPlaneX * vars->player.vec.prec.ang_sin
			+ vars->player.plane.y * vars->player.vec.prec.ang_cos;
	}
	else
	{
		sum.dx = (a->dx * vars->player.vec.cprec.ang_cos) - (a->dy * vars->player.vec.cprec.ang_sin);
		sum.dy = (a->dx) * vars->player.vec.cprec.ang_sin + (a->dy) * vars->player.vec.cprec.ang_cos;
		double oldPlaneX = vars->player.plane.x;
      	vars->player.plane.x = vars->player.plane.x * vars->player.vec.cprec.ang_cos - vars->player.plane.y * vars->player.vec.cprec.ang_sin;
      	vars->player.plane.y = oldPlaneX * vars->player.vec.cprec.ang_sin + vars->player.plane.y * vars->player.vec.cprec.ang_cos;
	}
	a->dx = sum.dx;
	a->dy = sum.dy;
}
