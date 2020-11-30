NAME = libftprintf.a

CC = gcc

HDR = ./includes/

CFLAGC = -Wall -Wextra -Werror

SRC = flags.c \
	  ft_print_int.c \
	  ft_print_c.c \
	  ft_print_u.c \
	  ft_print_x.c \
	  ft_printf.c \
	  ft_print_p.c \
	  ft_reader1.c \
	  different_functions.c \
	  ft_print_percent.c \

OBJ = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGC) -I$(HDR) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
