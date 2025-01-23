NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
		parse.c \
		sort.c \
		sorted.c \
		utils.c \
		free.c \
		./operation/swap.c \
		./operation/push.c \
		./operation/rotate.c \
		./operation/r_rotate.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft

libft/libft.a:
	make -C ./libft bonus

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
