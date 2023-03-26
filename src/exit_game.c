/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:28:11 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/03/26 21:11:52 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

/**
 * @brief function that take as parametr from mlx_hook
*/
int	exit_game(t_vars *vars)
{
	(void)vars;
	exit(0);
}
