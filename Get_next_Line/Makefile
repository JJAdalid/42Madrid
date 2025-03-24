CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=9 -I Get_next_line/
SRC = Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c main.c
BSRC = Get_next_line/get_next_line_bonus.c Get_next_line/get_next_line_utils_bonus.c main_bonus.c

OBJ = $(SRC:.c=.o)
BOBJ = ${BSRC:.c=.o}

NAME = gnl_test
BNAME = gnl_test_bonus

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

run : all
	chmod +x $(NAME)
	./$(NAME) hola.txt

run_bonus: bonus
	chmod +x $(BNAME)
	./$(BNAME) prueba1.txt hola.txt patata.txt

.PHONY: all clean fclean re bonus

