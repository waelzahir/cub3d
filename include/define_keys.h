#ifndef DEFINE_KEYS_H
# define DEFINE_KEYS_H

#ifndef MACOS

#  define RIGHT 65363
#  define LEFT 65361
#  define DOWN 65364
#  define UP 65362
#  define W 119
#  define S 115
#  define D 100
#  define A 97
#  define ESC 65307

#endif

#ifdef MACOS

#  define RIGHT 124
#  define LEFT 123
#  define DOWN 65364
#  define UP 65362
#  define W 13
#  define S 1
#  define D 2
#  define A 0

#endif


typedef	enum s_keys
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
} t_keys;
typedef	enum s_mask
{
	ON_KEYDOWN_MASK = (1L<<0),
	ON_KEYUP_MASK = (1L<<1),
} t_mask;

#endif