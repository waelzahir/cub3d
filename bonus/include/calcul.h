/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:35:58 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 13:35:59 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCUL_H
# define CALCUL_H

# include "types.h"

void	calculate_ray_pos_and_dir(t_game *game, t_pl *player, int x_screen);
void	set_map_cords_with_player(t_game *game, t_pl *player);
void	calculate_delta_x_and_y(t_game *game);
void	calculate_steps_init_side_dist(t_game *game, t_pl *player);
void	dda_calcul(t_game *game);
void	calculate_perpwalldist_and_hight(t_game *game);
void	calculate_lowest_and_highest_pixel(t_game *game);
void	calcul_game(t_game *game, t_pl *player, int x_screen);

// textures
void	get_x_textures(t_game *game, t_pl *player);

#endif