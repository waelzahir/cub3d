/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:28:11 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 11:50:26 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

static void free_text_image(t_vars *vars, t_data *texs)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(vars->mlx, texs[i].img);
		// free(texs[i].addr);
	}
}

static void	free_map(char **smap)
{
	int	i;

	i = -1;
	while (smap[++i])
		free(smap[i]);
	free(smap);
}

/**
 * @brief function that take as parametr from mlx_hook
*/
int	exit_game(t_vars *vars)
{
	free_map(vars->vgame.smap);
	free_text_image(vars, vars->vgame.textures);
	mlx_clear_window(vars->mlx, vars->win);
	exit(0);
	return 0;
}
