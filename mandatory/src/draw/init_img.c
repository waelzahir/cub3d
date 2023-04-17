/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:40:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 03:01:45 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	init_image_to_draw(t_vars *vars)
{
	t_game	*game;
	t_data	*data;

	game = &vars->vgame;
	data = &game->img;
	data->img = mlx_new_image(vars->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!data->img)
		return (-1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	if (!data->addr)
		return (-2);
	return (0);
}
