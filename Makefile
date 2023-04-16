# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2023/04/16 06:02:08 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash # Use bash syntax


# #################FLAGS#############################

OS = $(shell uname -s)
ifeq ($(OS),Linux)
	LFLAGS= -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz 
	IFLAGS= -I/usr/include  -O3 -g  -lm
	NEW_FILE = /tmp/newfile
	EMOJI = "🟩"
else
	NEW_FILE = ~/goinfre/newfile
	EMOJI = "⬛"
	LFLAGS=-lmlx -framework OpenGL -framework AppKit 
	IFLAGS= -D MACOS=1
endif


# #################HEADERS###########################
HEADERS = Cube3d.h  get_next_line.h  parser.h  types.h define_keys.h
HEADERS := $(addprefix include/, $(HEADERS))
# #################HEADERS_utils###########################
UHEADERS = 
UHEADERS := $(addprefix include/, $(UHEADERS))

# ################COMMANDS###########################

RM = rm -rf
CC = gcc
HEADERSFLAGS = -I include
CFLAG =  -Wall -Wextra -Werror $(HEADERSFLAGS)

# #################LOG_File##########################

LOG_FILE = lastcompiled.log

# ################SRCS_Objs##########################

SRC = 			vectors.c      init.c      point.c\
				mlx_hook.c     main.c      print_functions.c\
				exit_game.c    game_loop.c handling_keys.c\
				mouse_logic_for_bonus.c render.c
OBJ = $(addprefix obj/, $(SRC:.c=.o))

# ################SRCS_Objs_Utils####################

SRC_UTILS =		get_next_line.c get_next_line_utils.c ft_abs.c pixels.c
OBJ_UTILS = $(addprefix obj/utils/, $(SRC_UTILS:.c=.o))

# ################SRCS_Objs_Parser####################

SRC_PARSER = 	parser.c                   parser_parse_colors.c\
				parser_check_parsed_map.c  parser_parse_config.c\
				parser_error_free_data.c   parser_parse_map.c\
				parser_get_textures.c      parser_parse_player_data.c\
				parser_helpers.c           
OBJ_PARSER = $(addprefix obj/parser/, $(SRC_PARSER:.c=.o))

# ################SRCS_Objs_debug####################

SRC_DEBUG =		draw_2d_line.c
OBJ_DEBUG = $(addprefix obj/debug/, $(SRC_DEBUG:.c=.o))

# ################SRCS_Calcul####################

SRC_CALCUL = 	dda.c	perpWallDist_hight.c	raydir.c	step_sides.c\
				delta.c	player.c				start_end.c calcul_game.c\
				get_ray_polarity.c              x_textures.c
OBJ_CALCUL = $(addprefix obj/calcul/, $(SRC_CALCUL:.c=.o))
# ################SRCS_Draw####################

SRC_DRAW = 	line_to_img.c img_to_widow.c  init_img.c draw.c coloraze.c
OBJ_DRAW = $(addprefix obj/draw/, $(SRC_DRAW:.c=.o))

# ################OBJSALL############################

OBJ_ALLS =	$(OBJ) $(OBJ_PARSER)  $(OBJ_UTILS)\
			$(OBJ_DEBUG) $(OBJ_CALCUL) $(OBJ_DRAW)

# ################OBJDIR############################

OBJ_DIRS = obj obj/utils obj/parser obj/debug/ obj/calcul/ obj/draw/

# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'

CODE_SAVE_CURSOR='\033[s'
CODE_RESTORE_CURSOR='\033[u'
CODE_CURSOR_IN_SCROLL_AREA="\033[1A"

# ###############executable##########################

NAME = ./cube3d
LIBFT = libft/library/libft.a
ILIBFT = -I libft/include


# ###################################################

lines=$(shell tput lines)
cols=$(shell tput cols)
num=$(shell echo `find ./src -type f -name "*.c" | wc -l`)
i_num=0
x  = 0

# ###################################################


all : $(NAME)


$(NAME):  $(OBJ_ALLS) 
	@ printf "\033[$(lines);0f"
	@ tput el
	@printf  ${CODE_RESTORE_CURSOR}""
	@tput el
	@ printf ${GREEN}"\rMaking is done ✅\n"${NC}
	@$(CC) $(CFLAG)  $(OBJ_ALLS) $(ILIBFT) $(LIBFT)  $(LFLAGS) -g -o $(NAME)
	@ tput cvvis
	@ echo "---------------------------------------------------" | cat -  $(LOG_FILE) > $(NEW_FILE) && mv $(NEW_FILE)  $(LOG_FILE)

library :
	@ make -C libft
curser:
	@ tput cvvis

obj/%.o : src/%.c  $(HEADERS)  | library 
	@ mkdir -p $(OBJ_DIRS)
	@$ nu=$x ; if [[ $$nu -eq -1 ]] ; then \
	printf ${RE}"🔷 Making the--> "${NC} \
	 ; fi
	@if  $(CC) $(CFLAG)  $(IFLAGS)   -c $< -o $@; then \
		echo -n; \
		else \
			tput cvvis; \
			exit 1; \
		fi
	@tput civis
	$(eval x = $(shell echo "$(x) + 1" | bc ))
	@ printf $(notdir $@)"\n"
	@ printf  ${CODE_SAVE_CURSOR}""
	@ printf "\033[$(lines);0f"
	@ echo $< | cat -  $(LOG_FILE) > $(NEW_FILE) && mv $(NEW_FILE)  $(LOG_FILE)
	@number=`echo "$(x) * $(cols) / $(num)" | bc | tr -d '\n'` ; while [[ $$number -ne 1 ]] ; do \
		if [[ $$(( $$number % 2 )) -eq 0 ]]; then printf ${YELLOW}"${EMOJI}"${NC} ; fi ;\
        ((number = number - 1)) ; \
    done
	@printf  ${CODE_RESTORE_CURSOR}""
	@printf  ${CODE_CURSOR_IN_SCROLL_AREA}""
	@printf  ${CODE_SAVE_CURSOR}""
	@printf ${RE}"🔷 Making the  --> "${NC} 
	@tput el

clean :
	@ $(RM) $(OBJ_ALLS)
	@ $(RM) $(LOG_FILE)
	@ touch $(LOG_FILE)
	@ make clean -C libft
fclean : clean
	@ $(RM) $(NAME)
	@ make fclean -C libft

re : fclean all