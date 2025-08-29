NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra 

RM = rm -rf

SRCS = 	src/pipex.c\
		src/utils.c\
		libftprintf/libft/libft.a\

$(NAME) :
	make all -C libftprintf
	gcc $(CFLAGS) $(SRCS) -o $(NAME)


all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libftprintf

clean :
	$(RM) $(NAME)
	make clean -C libftprintf

re : fclean all

