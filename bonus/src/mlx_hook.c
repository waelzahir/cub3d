/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:57:15 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 06:03:02 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void game_hooks(t_vars *vars)
{
	game_loop(vars);
	mlx_hook(vars->win, ON_KEYDOWN, ON_KEYDOWN_MASK, press_key, vars);
	mlx_hook(vars->win, ON_KEYUP, ON_KEYUP_MASK, release_key,  vars);
	mlx_hook(vars->win, ON_MOUSEMOVE, ON_KEYUP_MASK, move_mouse,  vars);
	mlx_hook(vars->win, ON_DESTROY, 0, exit_game, vars);
	mlx_loop_hook(vars->mlx,  render, vars);
	mlx_loop(vars->mlx);
}