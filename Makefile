
EXEC = cub3d cub3d_bonus

all:
	make -C mandatory

bonus:
	make -C bonus

clean :
	make clean -C mandatory
	make clean -C bonus


M : all
	./cub3d mandatory/map/map.cub
B : bonus
	./cub3d_bonus bonus/map/map.cub

fclean : clean
	rm -rf $(EXEC)
re : fclean all

.PHONY: bonus
.SILENT: all bonus clean fclean re M B