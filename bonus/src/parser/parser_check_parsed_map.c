/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_parsed_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:15:24 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 06:26:01 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	check_axis(char **map, int x, int y)
{
	if (x == 0 || y == 0)
		return (1);
	if (!map[y + 1] || !map[y][x + 1])
		return (1);
	if (!char_is_allowed_in_side(map[y][x + 1]))
		return (1);
	if (!char_is_allowed_in_side(map[y][x - 1]))
		return (1);
	if (!char_is_allowed_in_side(map[y + 1][x]))
		return (1);
	if (!char_is_allowed_in_side(map[y - 1][x]))
		return (1);
	return (0);
}

int	check_if_map_closed(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' && check_axis(map, x, y))
				return (ft_putstr_fd("Error\nnaked '0' \n", 2), 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	get_map_sizes(char **map, int *x)
{
	int	len;
	int	y;

	y = -1;
	while (map[++y])
	{
		len = ft_strlen(map[y]);
		if (len > *x)
			*x = len;
	}
	return (y);
}

char	**duplicate_map(char **map, t_vars *_v)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = get_map_sizes(map, &i);
	new_map = ft_calloc(j + 1, sizeof(char *));
	if (!new_map)
		return (NULL);
	j = 0;
	_v->vgame.map_width = i;
	while (map[j])
	{
		new_map[j] = ft_calloc(i + 1, sizeof(char));
		if (!new_map[j])
			return (free_2d(new_map), NULL);
		ft_strlcpy(new_map[j], map[j], i + 1);
		j++;
	}
	_v->vgame.map_hight = j;
	return (new_map);
}

char	**parse_check_is_map_valid(char **oldmap, t_vars *_v)
{
	char	**new_map;

	new_map = duplicate_map(oldmap, _v);
	free_2d(oldmap);
	if (!new_map)
		return (ft_putstr_fd("MALLOC\n", 2), NULL);
	if (check_if_map_closed(new_map))
		return (free_2d(new_map), NULL);
	return (new_map);
}
