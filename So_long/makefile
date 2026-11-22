# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:46:34 by jadalid-          #+#    #+#              #
#    Updated: 2025/05/23 15:19:00 by jadalid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OBJS = $(SRCS:.c=.o)

SRCS =  ./src/render_objets.c \
		./src/read_map.c      \
		./src/ft_errors.c 	  \
		./src/validate_map.c  \
		./src/validate_path.c \
		./src/moves.c         \

INCLUDES = -I include ./libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd

LDFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 

all: $(NAME)

$(NAME): $(OBJS)
			@make -C libft
			@make -C minilibx-linux
			$(CC)  so_long.c $(LDFLAGS) $(SRCS) $(INCLUDES) -o $(NAME)
			
			

clean:
		$(MAKE) clean -C libft
		$(MAKE) clean -C minilibx-linux
		rm -rf $(OBJS)

fclean: clean
		$(MAKE) fclean -C libft
		$(MAKE) clean -C minilibx-linux
		@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean