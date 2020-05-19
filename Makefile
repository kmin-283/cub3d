NAME = cub3D

CC = gcc

CFLAG = -fsanitize=address

INCLUDES =	cub3d.h

OPTION = -lm -lmlx -lXext -lX11 -no-pie -L ./gnl -lftgnl -I $(INCLUDES)

SRCS =	main.c\
		keys.c\
		check.c\
		mapcheck.c\
		map.c\
		error.c\
		utils.c\
		mapgrid.c\
		unit_and_sprite.c\
		draw.c\
		cub3d.c\
		ray.c\
		ray2.c\
		move.c\
		bitmap.c\
		sprite.c

OBJS =	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME) : $(OBJS)
		make -C ./gnl
		$(CC) $(CFLAG) -o ${NAME} $(OBJS) $(OPTION)

clean:
		make clean -C ./gnl
		rm -f $(OBJS)

fclean:	clean
		make fclean -C ./gnl
		rm -f $(NAME)

re:		fclean all