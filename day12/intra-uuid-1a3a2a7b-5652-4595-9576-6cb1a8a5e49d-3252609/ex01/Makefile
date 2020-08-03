# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itollett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 17:45:14 by itollett          #+#    #+#              #
#    Updated: 2020/08/02 17:45:16 by itollett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${DIR}ft_putchar.c ${DIR}ft_swap.c ${DIR}ft_putstr.c ${DIR}ft_strlen.c ${DIR}ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

DIR 	= srcs/

NDIR	= includes/

FLAGS	= -Wall -Wextra -Werror

RM = rm -f

CC = gcc

NAME = libft.a

FT	= ft.h

.c.o:
			${CC} ${FLAGS} -I ${NDIR}${FT} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${OBGS} ${NAME}

re:			fclean all
