NAME = cub3D

CUB_SRCS = srcs/begining.c \
		   srcs/cub.c \
		   srcs/get_next_line.c \
		   srcs/map_parser.c \
		   srcs/moving_utils.c \
		   srcs/parse_texture.c \
		   srcs/parse_texture_ew.c \
		   srcs/parse_texture_ns.c \
		   srcs/parser.c \
		   srcs/player_parcer.c \
		   srcs/purge.c \
		   srcs/rays_and_hits.c \
		   srcs/rays_and_hits_2.c \
		   srcs/screenshot.c \
		   srcs/sprite.c \
		   srcs/sprites_cast.c \
		   srcs/tex_getting.c \
		   srcs/utils.c

CUB_H = ./includes/cub.h

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CUB_OBJS = $(CUB_SRCS:.c=.o)

LFLAGS = libmlx.dylib -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(CUB_OBJS)
	cd libft && make && make bonus && cd ../
	$(CC) $(CFLAGS) $(CUB_OBJS) -I$(CUB_H) ./libft/libft.a $(LFLAGS) -o $(NAME)

clean:
	rm -f srcs/*.o
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
