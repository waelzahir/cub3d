/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_polarity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:39:49 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/16 05:31:29 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"


void	get_ray_polarity(t_game	*game)
{
	if (!game->side  && game->rayDirX < 0)
    {
        game->raypole = WEST;
    }
    else if (!game->side  && game->rayDirX > 0)
    {
        game->raypole = EAST;
    }
    else if (game->side   && game->rayDirY < 0)
    {
        game->raypole = NORTH;
    }
    else if (game->side  && game->rayDirY > 0)
    {
        game->raypole = SOUTH;
    }
}