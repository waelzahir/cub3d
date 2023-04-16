/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:56:00 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 05:56:54 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cube3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
 
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	pixel_get(t_data *data, int x, int y)
{
	char	*dst;
 
	if (y >= data->height)
		y = data->height - 1;
	if (x >= data->height)
		x = data->width - 1;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}