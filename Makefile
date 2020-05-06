NAME = cub3D

CC = gcc

CFLAG = -fsanitize=address

INCLUDES =	./

OPTION = -lm -lmlx -lXext -lX11 -no-pie -L ./libft -lft -I $(INCLUDES)

SRCS =	cub3d.c\
		keys.c\
		check.c\
		main.c

OBJS =	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME) : $(OBJS)
		make -C ./libft
		$(CC) $(CFLAG) $(OPTION) -c $(OBJS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		fclean all