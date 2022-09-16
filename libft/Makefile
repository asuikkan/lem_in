# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asuikkan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 12:31:03 by asuikkan          #+#    #+#              #
#    Updated: 2021/11/03 13:07:02 by asuikkan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c	\
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c	\
 			ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c			\
			 ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c			\
			ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c			\
			ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c	\
			ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c		\
			ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
			ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c			\
			ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c			\
			ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strmapi.c			\
			ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c			\
			ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c			\
			ft_tolower.c ft_toupper.c ft_strclr.c ft_strclen.c			\
			ft_strjoin_free.c ft_strdup_free.c address.c ft_ftoa.c		\
			ft_anyitoa.c ftoa_helper.c ft_count_digits.c handlers1.c	\
			handlers2.c handlers3.c handlers4.c helpers.c				\
			modifiers1.c print.c ft_printf.c

OBJ		=	$(SRCS:.c=.o)

INCS	=	-I ./includes

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(INCS) -c $(SRCS)
	@@ar rc $@ $(OBJ)
	@@ranlib $@

clean:
	@@rm -f $(OBJ)

fclean: clean
	@@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
