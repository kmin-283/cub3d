NAME = cub3D

CC = gcc

CFLAG = -fsanitize=address

INCLUDES =	./mandatory/cub3d.h

OPTION = -L ./mlx -I . -I ./mlx -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd -no-pie -L ./gnl -lftgnl -I $(INCLUDES)

SRCS =	./mandatory/main.c\
		./mandatory/keys.c\
		./mandatory/check.c\
		./mandatory/mapcheck.c\
		./mandatory/map.c\
		./mandatory/error.c\
		./mandatory/utils.c\
		./mandatory/mapgrid.c\
		./mandatory/unit_and_sprite.c\
		./mandatory/draw.c\
		./mandatory/cub3d.c\
		./mandatory/ray.c\
		./mandatory/ray2.c\
		./mandatory/move.c\
		./mandatory/bitmap.c\
		./mandatory/sprite.c

OBJS =	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME) : $(OBJS)
		make -C ./gnl
		$(CC) $(CFLAG) -o ${NAME} $(OBJS) $(OPTION)

bonus:

clean:
		make clean -C ./gnl
		rm -f $(OBJS)

fclean:	clean
		make fclean -C ./gnl
		rm -f $(NAME)

re:		fclean all