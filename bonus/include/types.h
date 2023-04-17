/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 02:51:57 by ozahir            #+#    #+#             */
/*   Updated: 2023/04/17 06:04:32 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define MAPWIDTH 24
# define MAPHIGHT 24
# define SCREENWIDTH 1280
# define SCREENHEIGHT 960

typedef struct s_speed
{
	double	move;
	double	rotation;
}	t_speed;
typedef struct s_tframe
{
	double	time;
	double	oldtime;
}	t_tframe;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_prec
{
	double	ang_cos;
	double	ang_sin;
}	t_prec;

typedef struct s_vector
{
	double	dx;
	double	dy;
	double	angle;
	double	cangle;
	t_prec	prec;
	t_prec	cprec;
}	t_vector;

typedef struct s_pl
{
	t_point		pos_p;
	t_vector	vec;
	t_point		plane;
}	t_pl;

typedef struct s_img
{
	void	*wall;
}	t_img;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_data;

typedef struct s_game
{
	char		**smap;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			lineheight;
	int			mapx;
	int			mapy;
	int			map_hight;
	int			map_width;
	int			draw_start;
	int			draw_end;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			raypole;
	int			x_tex;
	int			color[2];
	t_data		img;
	t_data		textures[4];
}t_game;

typedef struct s_pressed
{
	int	hor;
	int	ver;
	int	rot;
	int	iter;
}	t_pressed;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		imgs;
	t_pl		player;
	t_tframe	times;
	t_speed		speed;
	t_game		vgame;
	t_pressed	press;
}	t_vars;

typedef enum s_directions
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_directions;

#endif