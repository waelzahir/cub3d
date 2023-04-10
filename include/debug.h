#ifndef DEBUG_H
# define DEBUG_H

# include "types.h"

void	print_game_infos(t_game *game, t_pl *player, int x_screen, int max_x);
void	draw_scale_point(t_vars *vars, t_point _point, int color);
void	dda_line_drawing(t_vector *vec, t_vars *vars);
void	print_magnitude(double dx, double dy);

#endif