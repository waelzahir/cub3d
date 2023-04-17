/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 09:39:22 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 08:42:07 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	is_valid_cords(int x, int y, t_vars *vars)
{
	if (x >= vars->vgame.map_width || y >= vars->vgame.map_hight)
		return (0);
	if (x < 0 || y < 0)
		return (0);
	return (1);
}
