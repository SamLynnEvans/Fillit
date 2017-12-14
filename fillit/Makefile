# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 11:12:50 by slynn-ev          #+#    #+#              #
#    Updated: 2017/12/14 21:05:07 by slynn-ev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = assign_tetriminos.c \
build_tetrimino_library.c \
check_for_match.c \
check_format.c \
get_coordinates.c \
main.c \
put_remove_tet.c \

NAME = fillit

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) re -C ../libft/
	gcc -c -Wall -Wextra -Werror $(SRC) -Ifillit.h
	gcc -o $(NAME) $(OBJ) ../libft/libft.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
