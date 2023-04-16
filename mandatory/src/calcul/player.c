/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 09:16:34 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void set_map_cords_with_player(t_game *game, t_pl *player)
{
	game->mapx = (int)player->pos_p.x;
	game->mapy = (int)player->pos_p.y;
}
