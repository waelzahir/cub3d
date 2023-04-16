/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_parse_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:26:35 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/12 03:32:06 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

int	check_numerical_only(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (ft_putstr_fd("Error\nspace between numbers\n", 2), 1);
		i++;
	}
	return (0);
}


int	color_fields_check(char **rgb)
{
	char	*tmp;
	int		i;

	i = 0;
	while (rgb[i])
	{
		tmp = ft_strtrim(rgb[i], " ");
		if (!tmp)
			return (1);
		if (check_numerical_only(tmp))
			return (free(tmp), 1);
		free(rgb[i]);
		rgb[i] = tmp;
		i++;
	}
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (1);
	return (0);
}

int	inside_get_color_from_str(char *color)
{
	char	**rgb;
	char	col[4];

	rgb = ft_split(color, ',');
	if (!rgb)
		return (ft_putstr_fd("Error\nmalloc\n", 2), -1);
	if (color_fields_check(rgb))
		return (free_2d(rgb), ft_putstr_fd("Error\nempty rgb value\n", 2), -1);
	if (ft_strlen(rgb[0]) > 3 || ft_strlen(rgb[1]) > 3 || ft_strlen(rgb[2]) > 3)
		return (free_2d(rgb), ft_putstr_fd("Error\n bigger than 255\n", 2), -1);
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255)
		return (free_2d(rgb), ft_putstr_fd("Error\n bigger than 255\n", 2), -1);
	col[0] = ft_atoi(rgb[2]);
	col[1] = ft_atoi(rgb[1]);
	col[2] = ft_atoi(rgb[0]);
	col[3] = 0;
	return (free_2d(rgb), *(int *)col);
}
 
int	rgb_allowed_sintax(char c)
{
	char	*ex;

	if (ft_isdigit(c))
		return (1);
	if (c == ' ' || c == ',')
		return (1);
	ft_putstr_fd("Error\n char: not allowed ascii code ", 2);
	ex = ft_itoa(c);
	if (!ex)
		return (1);
	ft_putendl_fd(ex, 2);
	free(ex);
	return (0);
}

int	check_rgb_value(char *rgb)
{
	int	i;
	int	point;

	point = 0;
	i = 0;
	while (rgb[i])
	{
		if (!rgb_allowed_sintax(rgb[i]))
			return (1);
		if (rgb[i] == ',')
			point++;
		i++;
	}
	if (point != 2)
		return (ft_putstr_fd("Error\nin rgb: wrong number of comma's\n", 2), 1);
	return (0);
}