#ifndef DEFINE_KEYS_H
# define DEFINE_KEYS_H

#if MACOS == 0
#  define RIGHT 124
#  define LEFT 123
#endif

#if MACOS == 1

#  define RIGHT 65363
#  define LEFT 65361
#endif

#  define DOWN 65364
#  define UP 65362
#  define W 13
#  define S 1
#  define D 2
#  define A 0

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

#endif