CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./Includes/Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = main.c ft_error.c stack_helpers.c Includes/ft_printf.c Includes/formats.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean obj files
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

# Clean everything (lib and obj)
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
