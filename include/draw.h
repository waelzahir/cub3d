/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:58:07 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/04/10 17:24:29 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "types.h"

int		init_image_to_draw(t_vars *vars);
void	draw_line_to_img(t_game *game, int x_screen);
void	draw_img_to_window(t_vars *vars);

#endif