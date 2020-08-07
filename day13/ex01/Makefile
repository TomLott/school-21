SRCS = ft_cat.c ft_write.c

OBJS = ${SRCS:.c=.o}

NAME = ft_cat

.c.o: 
		gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			gcc -Wall -Werror -Wextra -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${OBJS} ${NAME}

.PHONY:		clean fclean all
