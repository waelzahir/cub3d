/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:06:32 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 06:07:04 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void calculate_lowest_and_highest_pixel(t_game *game)
{
	game->draw_start = screenHeight / 2 - game->lineHeight / 2 ;
    if(game->draw_start < 0)
		game->draw_start = 0;
    game->draw_end = game->lineHeight / 2 + screenHeight / 2;
    if(game->draw_end >= screenHeight)
		game->draw_end = screenHeight - 1;
}
