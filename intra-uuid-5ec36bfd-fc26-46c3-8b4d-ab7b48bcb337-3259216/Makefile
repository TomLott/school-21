SRCS = main.c check.c create.c massive.c read.c

OBJS = ${SRCS:.c=.o}

CC   = gcc

NAME = BSQ

LIB = ft_bsq.h

FL = -Wall -Werror -Wextra

.c.o:	
			${CC} ${FL} -I ${LIB} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FL} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f ${OBJS}
fclean:		clean
			rm -f ${OBJS} ${NAME}
re:			fclean all

.PHONY:		all clean fclean re

