/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:18:56 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 05:26:24 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	textures_panic(int index, t_vars *_v, char	*tex)
{
	ft_putstr_fd("Error\ncouldn't use tex: ", 2);
	ft_putendl_fd(tex, 2);
	if (index == 0)
		return ;
	index--;
	while (index != -1)
	{
		mlx_destroy_image(_v->mlx, _v->vgame.textures[index].img);
		index--;
	}
	return ;
}

void	get_xpm_adresss(t_data *img)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

int	convert_xpm_file_to_data(t_vars *_v, char	**tex)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_v->vgame.textures[i].img = mlx_xpm_file_to_image(_v->mlx, tex[i],
				&_v->vgame.textures[i].width, &_v->vgame.textures[i].height);
		if (!_v->vgame.textures[i].img)
			return (textures_panic(i, _v, tex[i]), 1);
		get_xpm_adresss(&_v->vgame.textures[i]);
		i++;
	}
	return (0);
}
