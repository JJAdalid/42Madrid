CC = cc
CFLAGS = -Wall -Werror -Wextra -I.
SRC = get_next_line.c get_next_line_utils.c
BSRC = 

OBJ = $(SRC:.c=.o)

BOBJ = ${BSRC:.c=.o}

NAME = libgnl.a

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BOBJ)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

all: $(NAME)
