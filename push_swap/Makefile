# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/31 23:05:43 by yhruda            #+#    #+#              #
#    Updated: 2025/08/31 23:10:33 by yhruda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap

NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= src/push_swap.c src/validation.c src/actions.c src/actions_2.c src/actions_3.c \
			src/quick_sort.c src/separation.c src/initialization.c src/sort_3_and_5_element.c \
				src/global_sort.c src/finding_place.c

SRC2 	= src/checker.c src/validation.c src/actions.c src/actions_2.c src/actions_3.c \
			src/quick_sort.c src/separation.c src/initialization.c

OBJSFD 	= temporary

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))

OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I./includes

LIBFT_HDR 	= -I./includes/libft

LIB_BINARY	= -L./includes/libft -lft

LIBFT		= ./includes/libft/libft.a

all: $(LIBFT) ./includes/libft/libft.a $(NAME1) $(NAME2)

FORCE:		;

LIBFT		= ./includes/libft/libft.a

$(LIBFT):	FORCE
			make -C ./includes/libft

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(NAME1): $(OBJS1) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJS1) $(LIB_BINARY) -o $@

$(NAME2): $(OBJS2) $(LIBFT) ./includes/push_swap.h
	gcc -g $(OBJS2) $(LIB_BINARY) -o $@

clean:
	/bin/rm -f $(OBJS)
	rm -rf temporary/src/*.o
	make -C ./includes/libft clean

fclean: clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C ./includes/libft fclean

re: fclean all

