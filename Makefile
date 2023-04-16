
EXEC = cub3d

all:
	make -C mandatory

bonus:
	make -C bonus

clean :
	make fclean -C mandatory
	make fclean -C bonus

fclean : clean
	rm -rf $(EXEC)
re : fclean all

.PHONY: bonus
.SILENT: all bonus clean fclean re