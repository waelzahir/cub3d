/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:18:24 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 01:25:42 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	parser(char *file, t_vars *_v)
{
	int		fd;
	char	**configs;

	fd = check_file_details(file);
	if (fd < 0)
		return (1);
	configs = inside_parse_configs_fd(fd);
	if (!configs)
		return (1);
	if (check_parsed_configs(configs))
		return (close(fd), destroy2d_configs(configs), 1);
	if (inside_parse_get_color(configs, _v->vgame.color))
		return (close(fd), destroy2d_configs(configs), 1);
	_v->vgame.smap = inside_parse_config_map(fd, _v);
	if (!_v->vgame.smap)
		return (close(fd), destroy2d_configs(configs), 1);
	close(fd);
	_v->vgame.smap = parse_check_is_map_valid(_v->vgame.smap, _v);
	if (!_v->vgame.smap)
		return (destroy2d_configs(configs), 1);
	if (convert_xpm_file_to_data(_v, configs))
		return (free_2d(_v->vgame.smap), destroy2d_configs(configs), 1);
	destroy2d_configs(configs);
	return (0);
}

char	**inside_parse_configs_fd(int fd)
{
	char	**conf;
	int		i;

	i = -1;
	conf = ft_calloc(7, sizeof(char *));
	if (!conf)
		return (NULL);
	while (++i < 6)
	{
		if (inside_store_param(conf, inside_gnl_skipline(fd, 1)))
			return (destroy2d_configs(conf), NULL);
	}
	return (conf);
}

int	inside_parse_get_color(char **config, int *color)
{
	if (check_rgb_value(config[4]))
		return (1);
	if (check_rgb_value(config[5]))
		return (1);
	color[0] = inside_get_color_from_str(config[4]);
	color[1] = inside_get_color_from_str(config[5]);
	if (color[0] == -1 || color[1] == -1)
		return (1);
	return (0);
}

char	**inside_parse_config_map(int fd, t_vars *_v)
{
	char	*line;
	char	*map;

	map = NULL;
	line = inside_gnl_skipline(fd, 0);
	if (!line)
		return (ft_putstr_fd("Error\nmap not provided\n", 2), NULL);
	while (1)
	{
		if (check_map_line(line, _v) || is_map_line_empty(line))
			return (free(map), NULL);
		map = join_map(map, line);
		free(line);
		if (!map)
			return (ft_putstr_fd("MALLOC\n", 2), NULL);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (!_v->player.pos_p.x && !_v->player.pos_p.y)
		return (free(map), ft_putstr_fd("Error\nNo player_provided\n", 2), NULL);
	_v->vgame.smap = ft_split(map, '\n');
	return (free(map), _v->vgame.smap);
}
