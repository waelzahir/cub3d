/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:06:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 03:01:11 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calculate_lowest_and_highest_pixel(t_game *game)
{
	game->draw_start = SCREENHEIGHT / 2 - game->lineheight / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->lineheight / 2 + SCREENHEIGHT / 2;
	if (game->draw_end >= SCREENHEIGHT)
		game->draw_end = SCREENHEIGHT - 1;
}
