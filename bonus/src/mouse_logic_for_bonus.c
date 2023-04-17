/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_logic_for_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 01:55:07 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 08:49:25 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	move_mouse(int x, int y, t_vars *vars)
{
	if (x > SCREENWIDTH || x < 0 || y > SCREENHEIGHT || y < 0)
	{
		vars->press.rot = -1;
		return (0);
	}
	if (x > (SCREENWIDTH / 3) && x < (2 * SCREENWIDTH / 3))
	{
		vars->press.rot = -1;
		return (0);
	}
	if (x > (SCREENWIDTH / 2))
		vars->press.rot = RIGHT;
	else
		vars->press.rot = LEFT;
	return (0);
}
