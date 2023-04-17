/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:15:09 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 06:03:40 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

/**
 * @brief set first value of map
 * @param  structs playr and time inside t_vars
 * @return void
*/
static	void	init_var_game(t_vars *vars)
{
	vars->player.vec.angle = (PI / 50);
	vars->player.vec.cangle = -1 * vars->player.vec.angle;
	vars->player.vec.prec.ang_cos = cos(vars->player.vec.angle);
	vars->player.vec.prec.ang_sin = sin(vars->player.vec.angle);
	vars->player.vec.cprec.ang_cos = cos(vars->player.vec.cangle);
	vars->player.vec.cprec.ang_sin = sin(vars->player.vec.cangle);
	vars->times.time = 0;
	vars->times.oldtime = 0;
	vars->press.hor = -1;
	vars->press.ver = -1;
	vars->press.rot = -1;
}

int	init_img(t_vars *vars)
{
	int	a;

	vars->imgs.wall = mlx_xpm_file_to_image(vars->mlx,
			"./img/wall.xpm", &a, &a);
	if (!vars->imgs.wall)
		return (-1);
	return (0);
}

/**
 * @brief init vars
 * @param pointer to vars from main "vars"
 * @return 0 in case of sucesses and negative number in case of error
 */
int	init(t_vars *_vars, char *file)
{
	ft_bzero(_vars, sizeof(t_vars));
	_vars->mlx = mlx_init();
	if (init_img(_vars))
		return (-1);
	if (!_vars->mlx)
		return (ft_putstr_fd("init of mlx faild", 2), -1);
	_vars->win = mlx_new_window(_vars->mlx, SCREENWIDTH, SCREENHEIGHT, "Test");
	if (!_vars->mlx)
		return (perror("init of mlx window faild"), -2);
	if (parser(file, _vars))
	{
		mlx_destroy_window(_vars->mlx, _vars->win);
		return (-3);
	}
	init_var_game(_vars);
	return (0);
}
