/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:54:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 17:24:06 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	init_image_to_draw(t_vars *vars)
{
	t_game	*game;
	t_data	*data;

	game = &vars->vgame;
	data = &game->img;
	data->img = mlx_new_image(vars->mlx, screenWidth, screenHeight);
	if (!data->img)
		return (-1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	if (!data->addr)
		return (-2);
	return 0;
}

void	draw_line_to_img(t_game *game, int x_screen)
{
	int	i;
	int	pos;
	t_data	*data; 

	i = game->draw_start;
	data = &game->img;
	while (i < game->draw_end)
	{
		pos = (i * data->line_length) + (x_screen * (data->bits_per_pixel / 8));
		data->addr[pos] = 112; 
		data->addr[pos + 1] = 23;
		data->addr[pos + 2] = 122;
		i++;
	}
}

void	draw_img_to_window(t_vars *vars)
{
	t_game *game;

	game = &vars->vgame;
	mlx_put_image_to_window(vars->mlx, vars->win, game->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, game->img.img);
	ft_bzero(&game->img, sizeof(t_data));	
}