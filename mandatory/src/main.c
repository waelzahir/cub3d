/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:45:02 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 13:10:37 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	main(int ac, char	**av)
{
	t_vars	vars;

	if (ac != 2)
		return (ft_putendl_fd("Error\nprovide a file", 2), 1);
	if (init(&vars, av[1]))
		return (1);
	game_hooks(&vars);
	return (0);
}
