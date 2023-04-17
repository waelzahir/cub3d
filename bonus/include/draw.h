/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:58:07 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 13:36:32 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "types.h"

void	draw(t_game *game, int x_screen);
int		init_image_to_draw(t_vars *vars);
void	draw_line_to_img(t_game *game, int x_screen, double x);
void	draw_img_to_window(t_vars *vars);
void	colorize_floor_and_ceiling(t_game *game, int x);
// bonus
void	draw_scale_point(t_vars *vars, t_point _point, int color);
void	draw_2d_map(t_vars *vars);
void	dda_line_drawing(t_vector *vec, t_vars *vars, int x0, int y0);
void	draw_2d_map(t_vars *vars);
#endif