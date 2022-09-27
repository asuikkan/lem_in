# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <asuikkan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:04:49 by asuikkan          #+#    #+#              #
#    Updated: 2022/06/29 13:04:52 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

FLAGS	= -Wall -Werror -Wextra

<<<<<<< HEAD
NAME	= lem_in

INC		= ./includes

SRC		= main.c reader.c parse_room.c line_helpers.c error.c room_aux.c	\
		  parse_link.c hasher.c matrix.c distance.c pathfinder.c			\
		  llist_functions.c
=======
NAME	= lem-in

INC		= ./includes

SRC		= main.c reader.c parse_room.c line_helpers.c free.c room_aux.c		\
		  parse_link.c hasher.c pathfinder.c llist_functions.c				\
		  parse_ants.c pathset.c flow.c bfs.c bfs_tools.c adjacency.c		\
		  compare.c printer.c
>>>>>>> adj_rework

OBJ		= $(SRC:.c=.o)

LIB		= ./libft

LIB_INC	= ./libft/includes

all: $(NAME)

$(NAME):
	make -C $(LIB)
	$(CC) $(FLAGS) -I $(LIB_INC) -I $(INC) $(SRC) -o $(NAME) -L $(LIB) -lft

clean:
	make -C $(LIB) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIB) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
