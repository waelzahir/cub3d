/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 01:23:09 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 13:35:52 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include <stdio.h>
# include <fcntl.h>
// libft and gnl
# include "../libft/include/libft.h"
# include "get_next_line.h"

int		parser(char *file, t_vars *_v);
char	**inside_parse_configs_fd(int fd);
int		inside_parse_get_color(char **config, int *color);
char	**inside_parse_config_map(int fd, t_vars *_v);
void	set_plane_vec(t_point *p, char pole);
void	set_dir_vec(t_vector *vec, char pole);
int		check_map_line(char *line, t_vars *_v);
int		map_allowed_chars(char c, int player);
int		is_char_player(char c);
void	get_player_data(t_pl *player, char *c, int y, int x);
int		is_map_line_empty(char *line);
int		inside_store_param(char **conf, char *line);
int		get_config_key(char *config);
int		check_extention(char	*line);
int		line_considered_empty(char *line);
int		check_rgb_value(char *rgb);
int		rgb_allowed_sintax(char c);
int		inside_get_color_from_str(char *color);
int		color_fields_check(char **rgb);
int		check_numerical_only(char *num);
char	*inside_gnl_skipline(int fd, int trim);
int		check_parsed_configs(char **config);
int		check_file_details(char *file);
int		char_is_allowed_in_side(char c);
char	*join_map(char *s1, char *s2);
int		convert_xpm_file_to_data(t_vars *_v, char	**tex);
void	get_xpm_adresss(t_data *img);
void	textures_panic(int index, t_vars *_v, char	*tex);
void	free_2d(char **ptr);
void	destroy2d_configs(char **ptr);
char	**parse_check_is_map_valid(char **oldmap, t_vars *_va);
char	**duplicate_map(char **map, t_vars *_va);
int		get_map_sizes(char **map, int *x);
int		check_if_map_closed(char **map);
int		check_axis(char **map, int x, int y);
char	**reverse_map(char **map);

#endif