/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:23:27 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 06:24:03 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

char	*join_map(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

int	char_is_allowed_in_side(char c)
{
	return (c == '1' || c == '0');
}

int	check_file_details(char *file)
{
	int	fd;
	int	len;

	if (!file)
		return (ft_putstr_fd("Error\nfile not provided\n", 2), -1);
	len = ft_strlen(file) - 4;
	if (len < 0 || ft_strncmp(file + len, ".cub", 4))
		return (ft_putstr_fd("Error\nwrong map extention\n", 2), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nopening the file\n", 2), -1);
	return (fd);
}

int	check_parsed_configs(char **config)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (!config[i])
		{
			ft_putstr_fd("Error\nmalloc\n", 2);
			return (1);
		}
	}
	return (0);
}

char	*inside_gnl_skipline(int fd, int trim)
{
	char	*line;
	char	*ret;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		if (line_considered_empty(line))
			free(line);
		else if (trim == 1)
		{
			ret = ft_strtrim(line, " \n");
			free(line);
			return (ret);
		}
		else if (!trim)
			break ;
	}
	return (line);
}
