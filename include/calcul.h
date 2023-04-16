#ifndef CALCUL_H
# define CALCUL_H

# include "types.h"

void	calculate_ray_position_and_direction(t_game *game, t_pl *player, int x_screen);
void	set_map_cords_with_player(t_game *game, t_pl *player);
void	calculate_delta_x_and_y(t_game *game);
void	calculate_steps_init_side_dist(t_game *game, t_pl *player);
void	dda_calcul(t_game *game);
void	calculate_perpWallDist_and_hight(t_game *game);
void	calculate_lowest_and_highest_pixel(t_game *game);
void	calcul_game(t_game *game, t_pl *player, int x_screen);

// textures
void	get_x_textures(t_game *game, t_pl *player);

#endif