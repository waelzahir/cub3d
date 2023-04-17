/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:27:12 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 13:33:35 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "types.h"
# include "debug.h"
# include "parser.h"
# include "calcul.h"
# include "draw.h"
# include "define_keys.h"

# define PI 3.141592654
// function
int			init(t_vars *_vars, char *file);

// game_loop
int			game_loop(t_vars *vars);

// mlx_hook 
void		game_hooks(t_vars *vars);

t_point		new_point_s(int x, int y);
// vectors 
t_vector	new_vector_byvalue(double dx, double dy);
t_vector	*new_vector(int dx, int dy);
t_vector	add_vector(t_vector a, t_vector b);
t_vector	rotate_vector_byteta(t_vars *vars, t_vector *a, double teta);
void		rotate_vector(t_vars *vars, t_vector *a, double teta);
// exit_game
int			exit_game(t_vars *vars);
// utils 
double		ft_dabs(double num);
void		pixel_put(t_data *data, int x, int y, int color);
int			pixel_get(t_data *data, int x, int y);
int			is_valid_cords(int x, int y, t_vars *vars);
int			pixel_get(t_data *data, int x, int y);
void		pixel_put(t_data *data, int x, int y, int color);

// feat test: keys
int			press_key(int keycode, t_vars *var);
int			release_key(int keycode, t_vars *var);
void		move_horizontal(t_vars	*vars);
void		move_vertical(t_vars	*vars);
void		move_rotation(t_vars	*vars);
int			render(t_vars	*vars);
int			move_mouse(int x, int y, t_vars *vars);
void		get_ray_polarity(t_game	*game);

#endif