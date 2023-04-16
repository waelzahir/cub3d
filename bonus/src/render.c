/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 06:00:05 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 06:00:40 by tel-mouh         ###   ########.fr       */
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