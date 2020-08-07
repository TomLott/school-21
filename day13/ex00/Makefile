SRCS = ft_display_file.c

OBJS = ${SRCS:.c=.o}

NAME = ft_display_file

CC	= gcc

FLAGS  = -Wall -Werror -Wextra
.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean: 
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OBJS} ${NAME}

re:			fclean all

.PHONY:		clean fclean all
