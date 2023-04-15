/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_polarity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:39:49 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/15 06:10:19 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"


void	get_ray_polarity(t_game	*game)
{
	if (!game->side  && game->rayDirX < 0)
    {
        game->raypole = 3; 
    }
    else if (!game->side  && game->rayDirX > 0)
    {
        game->raypole = 2; 
    }
    else if (game->side   && game->rayDirY < 0)
    {
        game->raypole = 0; 
    }
    else if (game->side  && game->rayDirY > 0)
    {
        game->raypole = 1;
    }
}