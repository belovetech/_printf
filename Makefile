.PHONY: all clean oclean fclean re

CC = gcc
SRC = _printf.c utils.c checkflag.c
OBJ = $(SRC:%.c=%.o)
NAME = _printf
RM = rm -f

all: $(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all
