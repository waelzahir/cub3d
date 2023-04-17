/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:38:53 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 13:38:54 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "types.h"

void	print_game_infos(t_game *game, t_pl *player, int x_screen, int max_x);
void	draw_scale_point(t_vars *vars, t_point _point, int color);
void	dda_line_drawing(t_vector *vec, t_vars *vars, int x0, int y0);
void	print_magnitude(double dx, double dy);

#endif