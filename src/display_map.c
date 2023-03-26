/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:16:23 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/03/26 21:11:46 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cube3d.h"

void draw_wall(t_vars *vars)
{
	int i;
	int j;

	i = -1;
	(void)vars;
	while (++i < 24)
	{
		j = -1;
		while (++j < 24)
		{
			if (vars->map[i][j] >= 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.wall, i* (screenWidth / 24) + screenWidth, j* (screenHeight / 24));
		}
	}
	
}