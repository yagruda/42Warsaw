# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 12:17:09 by yhruda            #+#    #+#              #
#    Updated: 2025/09/01 12:17:25 by yhruda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= pipex

NAME_BONUS	= pipex_bonus

CC			= gcc

CFLAGS		=	-Wall -Werror -Wextra -g 

RM			= rm -f 

LIB			= ./libft/libft/libft.a

MAKE_LIBFT	= cd ./libft/libft && make

CLEAR_LIBFT	= cd ./libft/libft && make fclean

SRC			= ./src/main.c ./src/pipex.c ./src/ft_error_message.c \
				./src/ft_get_cmd.c

OBJS = ${SRC:%.c=%.o}

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(MAKE_LIBFT)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME)

clean	: 
	@$(MAKE)  -C ./libft/libft clean
	$(RM) $(OBJS)

fclean	: clean
	@$(MAKE) -C ./libft/libft fclean
	$(RM) $(NAME)

rmfile	: clean
	$(RM) outfile
	$(RM) infile
	$(RM) output

re		: fclean all