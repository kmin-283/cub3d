NAME = cub3D

B_NAME = cub3D_bonus

CC = gcc

CFLAG = -Wall -Werror -Wextra

INCLUDES =	./mandatory/cub3d.h

B_INCLUDES = ./bonus/cub3d_bonus.h

OPTION = -L ./mlx -I . -I ./mlx -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd -no-pie -L ./gnl -lftgnl -I $(INCLUDES)

B_OPTION = -L ./mlx -I . -I ./mlx -lmlx_Linux -lmlx -lXext -lm -lX11 -lbsd -no-pie -L ./gnl -lftgnl -I $(B_INCLUDES)

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

B_SRCS = ./bonus/main_bonus.c\
		./bonus/keys_bonus.c\
		./bonus/check_bonus.c\
		./bonus/mapcheck_bonus.c\
		./bonus/map_bonus.c\
		./bonus/error_bonus.c\
		./bonus/utils_bonus.c\
		./bonus/mapgrid_bonus.c\
		./bonus/unit_and_sprite_bonus.c\
		./bonus/draw_bonus.c\
		./bonus/cub3d_bonus.c\
		./bonus/ray_bonus.c\
		./bonus/ray2_bonus.c\
		./bonus/move_bonus.c\
		./bonus/bitmap_bonus.c\
		./bonus/sprite_bonus.c

OBJS =	$(SRCS:%.c=%.o)

B_OBJS = $(B_SRCS:%.c=%.o)

all:	$(NAME)

$(NAME) : $(OBJS)
		make -C ./gnl
		$(CC) $(CFLAG) -o ${NAME} $(OBJS) $(OPTION)

bonus	: $(B_NAME)

$(B_NAME):	$(B_OBJS)
		make -C ./gnl
		$(CC) $(CFLAG) -o $(B_NAME) $(B_OBJS) $(B_OPTION)

clean:
		make clean -C ./gnl
		rm -f $(OBJS)
		rm -f ${B_OBJS}

fclean:	clean
		make fclean -C ./gnl
		rm -f $(NAME)

re:		fclean all