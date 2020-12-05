#include "includes/cub.h"
#include "minilibx_mms_20200219/mlx.h"

int ft_work(char *arg, int i, t_all *all)
{
	//all->win->mlx = mlx_init();
	printf("111\n");
	(void)i;
	if (ft_parse(arg, all) < 0)
		return (0);
	return (0);
}

void ft_start(char *arg, int i)
{
	t_all	*all;
	t_win	win;
	t_err	err;
	t_map	map;
	t_player	player;
	t_point point;

	all = (t_all *)malloc(sizeof(t_all));
	win.mlx = NULL;
	win.win = NULL;
	win.img = NULL;
	win.addr = NULL;
	win.line_length = 0;
	win.bpp = 0;
	win.en = 0;
	point.x = 0;
	point.y = 0;
	player.x = 0;
	player.y = 0;
	player.dir	= 0;
	player.start = 0;
	player.end = 0;
	err.n	= 0;
	err.x = 0;
	map.x = 0;
	map.y = 0;
	ft_work(arg, i, all);
}

int main(int argc, char **argv)
{
	if (argc == 3 && file_format(argv[1], ".cub") && ft_strcmp(argv[2], "--save"))
		ft_start(argv[1], 1);
	else if (argc == 2 && file_format(argv[1], ".cub"))
		ft_start(argv[1], 0);
	else
		write(2, "Error: Invalid arguments\n", 26);
}