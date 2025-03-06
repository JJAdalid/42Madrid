# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juanje <juanje@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 01:00:35 by juanje            #+#    #+#              #
#    Updated: 2025/02/27 01:02:42 by juanje           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
SRC = 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

$(NAME): $(OBJ)
        ar rcs $(NAME) $(OBJ)

%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        rm -f $(OBJ) $(BOBJ)

fclean: clean
        rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 

all: $(NAME)