#ifndef TYPES_H
#define TYPES_H


#define mapWidth 24
#define mapHeight 24
#define screenWidth 1280
#define screenHeight 960

typedef struct s_speed
{
	double move;
    double rotation;
} t_speed;
typedef struct s_tframe
{
	double time;
	double oldtime;
} t_tframe;

typedef struct s_point
{
	double x;
	double y;
}t_point;

typedef struct s_prec
{
	double ang_cos;
	double ang_sin;
}t_prec;

typedef struct s_vector
{
	double dx;
	double dy;
	double angle;
	double cangle;
	t_prec prec;
	t_prec cprec;
} t_vector;

typedef struct s_pl
{
	t_point		pos_p;
	
	t_vector	vec;
	t_point		plane;
} t_pl;

typedef struct s_img
{
	void *wall;
}t_img;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_data;
typedef struct	s_game
{
	char		**smap;

	double		cameraX;
	double		rayDirX;
	double		rayDirY;


	double		sideDistX;
	double		sideDistY;
	
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			lineHeight;

	int			mapX;
	int			mapY;

	int			map_hight;
	int			map_width;

	int			draw_start;
	int			draw_end;

	int			stepX;
    int			stepY;

	int			hit;
	int			side;
	//colors: index 0 ceiling color , index 1 floor color
	int			color[2];
	

	t_data		img;
	/*
		textures indeixng:
			0: north
			1: south
			2: east:
			3: west
	*/
	t_data		textures[4];
}t_game;

typedef	struct s_pressed
{
	int	hor;
	int	ver;
	int	rot;
	int	iter;
} t_pressed;

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
} t_vars;


#endif