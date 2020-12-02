cmake_minimum_required(VERSION 3.12)
project(minirt C)

set(CMAKE_C_STANDARD 99)

add_library(minirt library.c library.h srcs/minirt.c includes/minirt.h libft/ft_setsplit.c srcs/checker.c libft/ft_strcmp.c srcs/parse_r_a_l_c.c)
add_library(minirt/get_next_line/get_next_line.h)
add_