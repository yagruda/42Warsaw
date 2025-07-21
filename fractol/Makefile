# Executable name
NAME	=	Fractol

# Source files (add your files from src/ here)
SRC	= \
	main.c \
	pixel_control.c \
	fractal_control.c \
	handle_control.c \

# .c to .o compilation
OBJ	=	$(SRC:.c=.o)

# compilation flags
CFLAGS	=	-Wall -Werror -Wextra -I./include

# Included Libraries flags
MLX_FLAGS	=	-Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
LIBFT_FLAGS = -LLibft -lft 
PRINTF_FLAGS = -Lprintf -lftprintf


# Path to Included Libraries
MLX_PATH = ./minilibx
LIBFT_PATH = ./Libft
PRINTF_PATH = ./printf


# Rules (no relink)
$(NAME):	$(OBJ) $(OBJ_MAIN) 
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	make -C $(PRINTF_PATH)
	cc -o $(NAME) $(OBJ) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(PRINTF_FLAGS)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY : all clean fclean re