/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 03:26:33 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 02:20:53 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	press_key(int keycode, t_vars *var)
{
	if (var->press.hor == -1 && (keycode == UP
			|| keycode == DOWN || keycode == W || keycode == S))
			var->press.ver = keycode;
	if (var->press.ver == -1 && (keycode == A || keycode == D))
			var->press.hor = keycode;
	if (var->press.rot == -1 && (keycode == LEFT || keycode == RIGHT))
			var->press.rot = keycode;
	if (keycode == ESC)
		exit_game(var);
	return (0);
}

int	release_key(int keycode, t_vars *var)
{
	if (var->press.ver == keycode)
		var->press.ver = -1;
	if (var->press.hor == keycode)
		var->press.hor = -1;
	if (var->press.rot == keycode)
		var->press.rot = -1;
	return (0);
}

void	move_vertical(t_vars	*vars)
{
	double	checkx;
	double	checky;

	if (vars->press.ver == UP || vars->press.ver == W)
	{
		checkx = vars->player.pos_p.x + (vars->player.vec.dx) * 0.12;
		if (vars->vgame.smap[(int)vars->player.pos_p.y][(int)checkx] == '0')
			vars->player.pos_p.x = checkx;
		checky = vars->player.pos_p.y + (vars->player.vec.dy) * 0.12;
		if (vars->vgame.smap[(int)checky][(int)vars->player.pos_p.x] == '0')
			vars->player.pos_p.y = checky;
	}
	else if (vars->press.ver == DOWN || vars->press.ver == S)
	{
		checkx = vars->player.pos_p.x - (vars->player.vec.dx) * 0.12;
		if (vars->vgame.smap[(int)vars->player.pos_p.y][(int)checkx] == '0')
			vars->player.pos_p.x = checkx;
		checky = vars->player.pos_p.y - (vars->player.vec.dy) * 0.12;
		if (vars->vgame.smap[(int)checky][(int)vars->player.pos_p.x] == '0')
			vars->player.pos_p.y = checky;
	}
}

void	move_horizontal(t_vars	*vars)
{
	double	checkx;
	double	checky;

	if (vars->press.hor == D)
	{
		checkx = vars->player.pos_p.x + (vars->player.plane.x) * 0.12;
		if (vars->vgame.smap[(int)vars->player.pos_p.y][(int)checkx] == '0')
			vars->player.pos_p.x = checkx;
		checky = vars->player.pos_p.y + (vars->player.plane.y) * 0.12;
		if (vars->vgame.smap[(int)checky][(int)vars->player.pos_p.x] == '0')
			vars->player.pos_p.y = checky;
	}
	if (vars->press.hor == A)
	{
		checkx = vars->player.pos_p.x - (vars->player.plane.x) * 0.12;
		if (vars->vgame.smap[(int)vars->player.pos_p.y][(int)checkx] == '0')
			vars->player.pos_p.x = checkx;
		checky = vars->player.pos_p.y - (vars->player.plane.y) * 0.12;
		if (vars->vgame.smap[(int)checky][(int)vars->player.pos_p.x] == '0')
			vars->player.pos_p.y = checky;
	}
}

void	move_rotation(t_vars	*vars)
{
	if (vars->press.rot == LEFT)
		rotate_vector(vars, &vars->player.vec, 1);
	if (vars->press.rot == RIGHT)
		rotate_vector(vars, &vars->player.vec, -1);
}
