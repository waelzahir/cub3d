/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:42:16 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 09:54:30 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cube3d.h"

void	print_game_infos(t_game *game, t_pl *player, int x_screen, int max_x)
{
	if (x_screen < 3 || (x_screen == (max_x / 2)) || max_x == x_screen)
	{
		if (max_x == x_screen)
			printf("\n==========Max========= \n");
		else if (x_screen == (max_x / 2))
			printf("\n========Middle======== \n");
		else
			printf("\n=========start======== \n");
		printf("camera          : %.2f\n\n", game->camerax);
		printf("player vector x : %.2f\n", player->vec.dx);
		printf("player vector y : %.2f\n\n", player->vec.dy);
		printf("game->raydirx   : %.2f\n", game->raydirx);
		printf("game->raydiry   : %.2f\n\n", game->raydiry);
		printf("====================== \n");
		printf("game->deltadistx : %.2f\n", game->deltadistx);
		printf("game->deltadisty : %.2f\n", game->deltadisty);
		printf("game->sidedistx : %.2f\n", game->sidedistx);
		printf("game->sidedisty : %.2f\n", game->sidedisty);
		printf("====================== \n");
		printf("x_screen        : %d\n", x_screen);
		printf("perpwalldist    : %f\n", game->perpwalldist);
		printf("side            : %d\n", game->side);
		printf("====================== \n");
		print_magnitude(game->raydirx, game->raydiry);
		printf("====================== \n\n\n");
	}
}

void	print_magnitude(double dx, double dy)
{
	printf("magnitude       : %.4f\n", sqrt(pow(dy, 2) + pow(dx, 2)));
}
