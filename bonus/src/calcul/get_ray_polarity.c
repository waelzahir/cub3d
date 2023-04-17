/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_polarity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:39:49 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 06:11:37 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	get_ray_polarity(t_game	*game)
{
	if (!game->side && game->raydirx < 0)
	{
		game->raypole = WEST;
	}
	else if (!game->side && game->raydirx > 0)
	{
		game->raypole = EAST;
	}
	else if (game->side && game->raydiry < 0)
	{
		game->raypole = NORTH;
	}
	else if (game->side && game->raydiry > 0)
	{
		game->raypole = SOUTH;
	}
}
