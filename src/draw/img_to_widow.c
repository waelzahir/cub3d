/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_widow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:40:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 17:41:09 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	draw_img_to_window(t_vars *vars)
{
	t_game *game;

	game = &vars->vgame;
	mlx_put_image_to_window(vars->mlx, vars->win, game->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, game->img.img);
	ft_bzero(&game->img, sizeof(t_data));	
}
