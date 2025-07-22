NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iminilibx


SRCS = \
	main.c \
	pixel_control.c \
	handle_control.c \
	fractal_control.c \

OBJS = $(SRCS:.c=.o)

PRINTF_DIR = libftprintf
PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR = $(PRINTF_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a


MINI_LIBX_DIR = minilibx
MINI_LIBX = $(MINI_LIBX_DIR)/libmlx.a
MINI_LIBX_FLAGS = -L$(MINI_LIBX_DIR) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


all: $(NAME)

$(NAME): $(OBJS) $(PRINTF) $(MINI_LIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) $(MINI_LIBX) $(MINI_LIBX_FLAGS) -o $(NAME)


$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINI_LIBX):
	$(MAKE) -C $(MINI_LIBX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINI_LIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINI_LIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re

