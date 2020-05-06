NAME = libftgnl.a

CC = gcc

CFLAG = -Wall -Werror -Wextra

SRCS =	get_next_line.c\
		get_next_line_utils.c\

OBJS =	$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
		make -C ../libft
		$(CC) $(CFLAG) -c $(SRCS)
		cp ../libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -rf $(OBJS)
		make clean -C ../libft

fclean:
		rm -rf $(NAME)
		make fclean -C ../libft

re: fclean all