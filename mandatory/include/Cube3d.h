/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:36:11 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 02:45:53 by ozahir           ###   ########.fr       */
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

int		init(t_vars *_vars, char *file);
int		init_img(t_vars *vars);
void	game_hooks(t_vars *vars);
int		exit_game(t_vars *vars);
int		game_loop(t_vars *vars);
int		press_key(int keycode, t_vars *var);
int		release_key(int keycode, t_vars *var);
void	move_vertical(t_vars	*vars);
void	move_horizontal(t_vars	*vars);
void	move_rotation(t_vars	*vars);
int		render(t_vars	*vars);
void	rotate_vector(t_vars *vars, t_vector *a, double teta);
double	ft_dabs(double num);
void	pixel_put(t_data *data, int x, int y, int color);
int		pixel_get(t_data *data, int x, int y);

#endif