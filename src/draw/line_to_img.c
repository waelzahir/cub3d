/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:54:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 18:04:20 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	draw_line_to_img(t_game *game, int x_screen)
{
	int	i;
	int	pos;
	t_data	*data; 

	i = game->draw_start;
	data = &game->img;
	while (i <= game->draw_end)
	{
		pos = (i * data->line_length) + (x_screen * (data->bits_per_pixel / 8));
		if (game->side == 1)
		{
			data->addr[pos] = 112; 
			data->addr[pos + 1] = 23;
			data->addr[pos + 2] = 122;	
		}
		else
		{
			data->addr[pos] = 0; 
			data->addr[pos + 1] = 23;
			data->addr[pos + 2] = 122;	
		}
		i++;
	}
}
