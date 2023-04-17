/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:45:02 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 05:54:18 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	_main(int ac, char	**av)
{
	t_vars	vars;

	if (ac != 2)
		return (ft_putendl_fd("Error\nprovide a file", 2),1);
	if (init(&vars, av[1]))
		return (1);
	game_hooks(&vars);
	return (0);
}

int main(int ac, char	**av)
{
	_main(ac, av);
	system("leaks cub3d");
}
