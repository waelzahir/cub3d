/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:54:12 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 06:17:39 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	draw(t_game *game, int x_screen)
{
	colorize_floor_and_ceiling(game, x_screen);
	draw_line_to_img(game, x_screen, game->x_tex);
}
