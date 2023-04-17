/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:01:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 13:10:22 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	rotate_vector(t_vars *vars, t_vector *a, double teta)
{
	t_vector	sum;
	t_prec		angle;
	double		oldplane_x;

	if (teta == 1)
		angle = vars->player.vec.prec;
	else
		angle = vars->player.vec.cprec;
	sum.dx = (a->dx * angle.ang_cos)
		- (a->dy * angle.ang_sin);
	sum.dy = (a->dx) * angle.ang_sin
		+ (a->dy) * angle.ang_cos;
	oldplane_x = vars->player.plane.x;
	vars->player.plane.x = vars->player.plane.x * angle.ang_cos
		- vars->player.plane.y * angle.ang_sin;
	vars->player.plane.y = oldplane_x * angle.ang_sin \
		+ vars->player.plane.y * angle.ang_cos;
	a->dx = sum.dx;
	a->dy = sum.dy;
}
