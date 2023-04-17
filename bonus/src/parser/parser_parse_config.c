/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_config.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:24:10 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 06:23:45 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	line_considered_empty(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return (1);
	while (line [i] && line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (1);
	return (0);
}

int	check_extention(char	*line)
{
	int	len;

	len = ft_strlen(line);
	if (len < 7)
		return (1);
	len -= 4;
	if (!ft_strncmp(line + len, ".xpm", 4))
		return (0);
	return (1);
}

int	get_config_key(char *config)
{
	if (!ft_strncmp(config, "NO ", 3))
		return (0);
	if (!ft_strncmp(config, "SO ", 3))
		return (1);
	if (!ft_strncmp(config, "EA ", 3))
		return (2);
	if (!ft_strncmp(config, "WE ", 3))
		return (3);
	if (!ft_strncmp(config, "C ", 2))
		return (4);
	if (!ft_strncmp(config, "F ", 2))
		return (5);
	return (-1);
}

int	inside_store_param(char **conf, char *line)
{
	int	key;

	if (!line)
		return (ft_putstr_fd("Error\nInsuficient configs\n", 2), 1);
	key = get_config_key(line);
	if (key == -1)
		return (free(line), ft_putstr_fd("Error\ninvalid config\n", 2), 1);
	if (conf[key])
		return (free(line), ft_putstr_fd("Error\nduplicated config\n", 2), 1);
	if (key < 4 && check_extention(line))
		return (free(line), ft_putstr_fd("Error\n!xpm extention\n", 1), 1);
	if (key < 4)
		conf[key] = ft_strtrim(line + 3, " ");
	else
		conf[key] = ft_strtrim(line + 2, " ");
	return (free(line), 0);
}
