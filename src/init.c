/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:15:09 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/03 11:38:06 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"


/**
 * @brief set first value of map
 * @param  structs playr and time inside t_vars
 * @return void
*/
static void init_var_game(t_vars *vars)
{
	vars->player.vec.angle = (PI / 23);
	vars->player.vec.cangle = -1 * vars->player.vec.angle;
	vars->player.vec.prec.ang_cos = cos(vars->player.vec.angle);
	vars->player.vec.prec.ang_sin = sin(vars->player.vec.angle);
	vars->player.vec.cprec.ang_cos = cos(vars->player.vec.cangle);
	vars->player.vec.cprec.ang_sin = sin(vars->player.vec.cangle);
	vars->times.time = 0;
	vars->times.oldtime = 0;
}

void init_img(t_vars *vars)
{
	int a;
	vars->imgs.wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm",&a ,&a);
}

/**
 * @brief init vars
 * @param pointer to vars from main "vars"
 * @return 0 in case of sucesses and negative number in case of error
 */
int init(t_vars *_vars, char	*file)
{
	bzero(_vars, sizeof(t_vars));
	_vars->mlx = mlx_init();
	init_img(_vars);
	if (!_vars->mlx)
		return (perror("init of mlx faild"), -1);
	_vars->win = mlx_new_window(_vars->mlx, screenWidth, screenHeight, "Test");
	if (!_vars->mlx)
		return (perror("init of mlx window faild"), -2);
	
	if (parser(file, _vars))
		return (-3);
	
	init_var_game(_vars);
	return (0);
}
