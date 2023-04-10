/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:28:11 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/08 00:03:28 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

/**
 * @brief function that take as parametr from mlx_hook
*/
int	exit_game(t_vars *vars)
{
	(void)vars;
	ft_putendl_fd("exit game", 2);
	exit(0);
}
