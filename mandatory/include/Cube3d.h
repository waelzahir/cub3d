#ifndef Cube3d_H
# define Cube3d_H

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
int		init(t_vars *_vars, char *file);

// utils
void	print_map_on_terminal(int map[mapWidth][mapHeight]);

// game_loop
int		game_loop(t_vars *vars);

// mlx_hook 
void	game_hooks(t_vars *vars);

// points
void	init_point(t_point *_point, int x, int y);
void	point_set_x(t_point *_point, int x);
void	point_set_y(t_point *_point, int y);
t_point	new_point_s(int x, int y);

// draw line (DDA)

// vectors 
t_vector	new_vector_byvalue(double dx, double dy);
t_vector	*new_vector(int dx, int dy);
t_vector	add_vector(t_vector a, t_vector b);
t_vector	rotate_vector_byteta(t_vars *vars, t_vector *a, double teta);
void		rotate_vector(t_vars *vars, t_vector *a, double teta);
// exit_game
int		exit_game(t_vars *vars);



// utils 
double	ft_dabs(double num);
void	pixel_put(t_data *data, int x, int y, int color);
int		pixel_get(t_data *data, int x, int y);
int		is_valid_cords(int x , int y, t_vars *vars);

// feat test: keys
int		press_key(int keycode, t_vars *var);
int		release_key(int keycode, t_vars *var);
void	move_horizontal(t_vars	*vars);
void	move_vertical(t_vars	*vars);
void	move_rotation(t_vars	*vars);
int		render(t_vars	*vars);
int     move_mouse(int x, int y , t_vars *vars);
void	get_ray_polarity(t_game	*game);
int		pixel_get(t_data *data, int x, int y);
void	pixel_put(t_data *data, int x, int y, int color);

#endif