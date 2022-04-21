SRCS	= ${wildcard *.c}
OBJS	= ${SRCS:.c=.o}
NAME	= ft_display_file

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean
