# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:46:34 by jadalid-          #+#    #+#              #
#    Updated: 2025/05/08 16:19:30 by jadalid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS = -Wall -Wextra -Werror 

OBJS = $(SRCS:.c=.o)

SRCS = ./src/check_map.c ./src/read_map.c ./src/ft_errors.c ./src/validate_map.c 

INCLUDES = -I include ./libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS)
			@make -C libft
			@make -C minilibx-linux
			@gcc -fsanitize=address -fsanitize=leak ./src/so_long.c $(SRCS) $(INCLUDES) -o $(NAME)

clean:
		@make clean -C libft
		@make clean -C minilibx-linux
		rm -rf $(OBJS)

fclean:
		@make fclean -C libft
		@make clean -C minilibx-linux
		@rm -rf $(OBJS)
		@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean