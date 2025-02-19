CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42 -I Get_next_line/
SRC = Get_next_line/get_next_line.c Get_next_line/get_next_line_utils.c main.c
BSRC = 

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
	./$(NAME) prueba.txt

run_bonus: bonus
	chmod +x $(BNAME)
	./$(BNAME) prueba.txt prueba1.txt prueba2.txt

.PHONY: all clean fclean re bonus

