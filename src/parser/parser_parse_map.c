/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:23:49 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/06 02:10:10 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	is_map_line_empty(char *line)
{
	int	i;
	int	space;

	space = 0;
	i = 0;
	if (line[0] == '\n')
		return (free(line), ft_putstr_fd("Error\n empty line in map\n", 2), 1);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (space + 1 == i)
		return (free(line), ft_putstr_fd("Error\n empty line in map\n", 2), 1);
	return (0);
}

void	get_player_data(t_pl *player, char *c, int y, int x)
{
	player->pos_p.x = x;
	player->pos_p.y = y;
	set_dir_vec(&player->vec, *c);
	set_plane_vec(&player->plane, *c);
	*c = '0';
}

int	is_char_player(char c)
{
	return (c == 'E' || c == 'W' || c == 'S' || c == 'N');
}

int	map_allowed_chars(char c, int player)
{
	if (player && is_char_player(c))
		return (1);
	return (c == '0' || c == '1' || c == ' ');
}

int	check_map_line(char *line, t_vars *_v)
{
	int			i;
	static int	y;
	static char	c;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!map_allowed_chars(line[i], 1))
			return (free(line),
				ft_putstr_fd("Error\nchar not allowed in map\n", 2), 1);
		if (is_char_player(line[i]) && c)
			return (free(line), ft_putstr_fd("Error\n multiple players\n", 2), 1);
		if (is_char_player(line[i]) && !c)
		{
			get_player_data(&_v->player, &line[i], y, i);
			c++;
		}
		i++;
	}
	y++;
	return (0);
}