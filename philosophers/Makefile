CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c) 
OBJ = $(SRC:.c=.o)
NAME = philosophers

OBJDIR = obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Compile object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean obj files
clean:
	rm -rf $(OBJDIR)
	rm -f *.o */*.o */*/*.o

# Clean everything (lib and obj)
fclean: clean
	rm -f $(NAME)
	rm -f *.o */*.o */*/*.o

re: fclean all

.PHONY: all clean fclean re
