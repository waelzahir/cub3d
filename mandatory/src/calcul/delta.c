/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:57:41 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 01:11:04 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	calculate_delta_x_and_y(t_game *game)
{
	if (!game->raydirx)
		game->deltadistx = 1e30;
	else
		game->deltadistx = ft_dabs(1 / game->raydirx);
	if (!game->raydiry)
		game->deltadisty = 1e30;
	else
		game->deltadisty = ft_dabs(1 / game->raydiry);
	game->perpwalldist = 0;
	game->hit = 0;
}
