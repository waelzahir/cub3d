/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 05:54:12 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 06:10:23 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	draw(t_game *game,int x_screen)
{
		colorize_floor_and_ceiling(game, x_screen);
		draw_line_to_img(game, x_screen, game->x_tex);
}