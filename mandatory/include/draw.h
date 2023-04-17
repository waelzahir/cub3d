/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:58:07 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/17 02:49:55 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "types.h"

void	draw(t_game *game, int x_screen);
int		init_image_to_draw(t_vars *vars);
void	draw_line_to_img(t_game *game, int x_screen, double x);
void	draw_img_to_window(t_vars *vars);
void	colorize_floor_and_ceiling(t_game	*game, int x);

#endif