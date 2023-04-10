/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_player_data.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:13:32 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/06 05:20:08 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

void	set_plane_vec(t_point *p, char pole)
{
	if (pole == 'N')
	{
		p->x = -0.66;
		p->y = 0;
	}
	if (pole == 'S')
	{
		p->x = 0.66;
		p->y = 0;
	}
	if (pole == 'E')
	{
		p->x = 0;
		p->y = 0.66;
	}
	if (pole == 'W')
	{
		p->x = 0;
		p->y = -0.66;
	}
}

void	set_dir_vec(t_vector *vec, char pole)
{
	if (pole == 'N')
	{
		vec->dx = 0;
		vec->dy = -1;
	}
	if (pole == 'S')
	{
		vec->dx = 0;
		vec->dy = 1;
	}
	if (pole == 'E')
	{
		vec->dx = -1;
		vec->dy = 0;
	}
	if (pole == 'W')
	{
		vec->dx = 1;
		vec->dy = 0;
	}
}
