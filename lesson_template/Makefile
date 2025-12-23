CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LIBFT_DIR = ./Includes/Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = $(wildcard *.c) Includes/ft_printf.c Includes/formats.c
OBJ = $(SRC:.c=.o)
NAME = lesson_threads

OBJDIR = obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Compile object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean obj files
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJDIR)
	rm -f *.o */*.o */*/*.o

# Clean everything (lib and obj)
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f *.o */*.o */*/*.o

re: fclean all

.PHONY: all clean fclean re
