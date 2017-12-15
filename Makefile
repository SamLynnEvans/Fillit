# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 11:12:50 by slynn-ev          #+#    #+#              #
#    Updated: 2017/12/15 15:33:54 by slynn-ev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = assign_tetriminos.c \
build_tetrimino_library.c \
check_for_match.c \
check_format.c \
get_coordinates.c \
main.c \
put_remove_tet.c \
print_square.c \
get_size.c \

NAME = fillit
LIB = libft
LIB_A = libft.a
FLAG = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
all: $(NAME)

%.o: %.c
	 gcc -c $(FLAG) $<

$(NAME): $(OBJ) $(LIB)
	make -C $(LIB)
	gcc $(FLAG) $(OBJ) $(LIB)/$(LIB_A) -o $(NAME) -Ifillit.h

clean:
	make clean -C $(LIB)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIB)/$(LIB_A)

re: fclean all

.PHONY: all clean fclean re
