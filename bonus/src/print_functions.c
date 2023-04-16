/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:19:50 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/03/26 21:12:07 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"



/**
 * @brief print funcion numbers in map
 * @return return void
*/
void	print_map_on_terminal(int map[mapWidth][mapHeight])
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < mapWidth)
	{
		j = -1;
		while (++j < mapHeight)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}
