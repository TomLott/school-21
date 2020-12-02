#ifndef MINIRT_MINIRT_H
#define MINIRT_MINIRT_H

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"

typedef struct s_mini
{
	int save;
	int colour;
	void	*mlx;
	void	*mlx_win;
	char	**processed;
	char	*line;
}							t_mini;

#endif //MINIRT_MINIRT_H
