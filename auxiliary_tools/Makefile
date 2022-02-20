SRC = *.c ex*/*.c
CC = gcc
OBJ = *.o
CFLAGS += -Wall -Werror -Wextra
DEBUGFLAGS += -Wall -Werror -Wextra -g
NAME = c02.out
FIND = find ex* -type f ! -name main.c ! -name Makefile ! -name *.out

$(NAME):
	${CC} ${CFLAGS} $(SRC) -o ${NAME}

.PHONY: all clean fclean re check

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

debug: fclean
	${CC} ${DEBUGFLAGS} ${CFLAGS} $(SRC) -o ${NAME}
	rm -f $(OBJ)

check:
	norminette `${FIND}` -R CheckForbiddenSourceHeader