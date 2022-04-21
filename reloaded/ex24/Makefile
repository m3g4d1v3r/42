SRCD	= srcs/
SRCS	= ft_putchar.c \
		  ft_putstr.c \
		  ft_strcmp.c \
		  ft_strlen.c \
		  ft_swap.c
INCD	= includes/
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra -I${INCD}

%.o:		${SRCD}%.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
