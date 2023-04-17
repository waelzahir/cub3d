/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 06:00:05 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 09:41:50 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	render(t_vars	*vars)
{

	if (vars->press.hor != -1)
		move_horizontal(vars);
	if (vars->press.ver != -1)
		move_vertical(vars);
	if (vars->press.rot != -1)
		move_rotation(vars);
	if (vars->press.hor != -1 || vars->press.ver != -1 || vars->press.rot != -1)
		game_loop(vars);
	return (0);
}
