/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:58:07 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/16 01:36:28 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "types.h"

int		init_image_to_draw(t_vars *vars);
void	draw_line_to_img(t_game *game, int x_screen , double x);
void	draw_img_to_window(t_vars *vars);

#endif