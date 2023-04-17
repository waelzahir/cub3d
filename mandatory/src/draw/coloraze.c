/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloraze.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:57:58 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 03:02:18 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	colorize_floor_and_ceiling(t_game	*game, int x)
{
	int	st;
	int	en;

	st = -1;
	en = game->draw_end - 1;
	while (++st < game->draw_start)
		pixel_put(&game->img, x, st, game->color[0]);
	while (++en < SCREENHEIGHT - 1)
		pixel_put(&game->img, x, en, game->color[1]);
}
