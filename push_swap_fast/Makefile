NAME = push_swap

SRC = $(wildcard src/*.c utils/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I./includes

LIBFT_PATH = ./libftprintf
PRINTF_FLAGS = -L$(LIBFT_PATH) -lftprintf

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	cc -o $(NAME) $(OBJ) $(CFLAGS) $(PRINTF_FLAGS) -L$(LIBFT_PATH)/libft -lft

all: $(NAME)

clean:
	@${MAKE} -C $(LIBFT_PATH) fclean
	rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re