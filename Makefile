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

NAME	= lem_in

INC		= ./includes

SRC		= main.c reader.c parse_info.c line_helpers.c error.c

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