/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_widow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:40:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 06:17:19 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	draw_img_to_window(t_vars *vars)
{
	t_game	*game;

	game = &vars->vgame;
	mlx_put_image_to_window(vars->mlx, vars->win, game->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, game->img.img);
	ft_bzero(&game->img, sizeof(t_data));
}
