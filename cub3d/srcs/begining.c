#include "../includes/cub.h"
void ft_rays_hits(t_all *all)
{
	t_ray ray;

	all->ray = ray;
	ray.x = 0;
	ray.y = 0;
	ft_screen(all);
}

int inside_map(double x, t_all *all, int i, double line)
{
	int c;

	c = all->map.table[(int)line][(int)x];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return 1;
	if (i == 1)
		return (x < (int)ft_strlen(all->map.table[(int)(x)]) && x > 0) ? 1 : 0;
	if (i == 0)
		return (1);
	return (0);
}

int can_do(int c)
{
	return (c == OK || c == OK + 1 || c == 'N' || c == 'W' || c == 'E' || c == 'S') ? 1 : 0;
}

void ft_move_tb(t_all *all, int i)
{
	int n;

	n = (i == 'W') ? 1 : -1;
	if (inside_map((all->pl.x + n * all->pl.dir_x * MOVESPEED/10), all, 0, (all->pl.y)) && can_do(all->map.table[(int)(all->pl.y)][(int)(all->pl.x + n * all->pl.dir_x * MOVESPEED/10)]))
		all->pl.x += (n * all->pl.dir_x * MOVESPEED/10);
	if (inside_map((all->pl.y + n * all->pl.dir_y * MOVESPEED/10), all, 1, (all->pl.y)) && can_do(all->map.table[(int)(all->pl.y + n * all->pl.dir_y * MOVESPEED/10)][(int)(all->pl.x)]))
		all->pl.y += (n * all->pl.dir_y * MOVESPEED/10);
}

void ft_move(t_all *all, int i)
{
	int n;

	n = (i == 'D') ? 1 : -1;
	if (inside_map((all->pl.x - n * all->pl.dir_y * MOVESPEED/10), all, 0, (all->pl.y)) && can_do(all->map.table[(int)(all->pl.y)][(int)(all->pl.x - n * all->pl.dir_y * MOVESPEED/10)]))
		all->pl.x -= (n * all->pl.dir_y * MOVESPEED/10);
	if (inside_map((all->pl.y + n * all->pl.dir_x * MOVESPEED/10), all, 1, (all->pl.y)) && can_do(all->map.table[(int)(all->pl.y + n * all->pl.dir_x * MOVESPEED/10)][(int)(all->pl.x)]))
		all->pl.y += (n * all->pl.dir_x * MOVESPEED/10);
}

void ft_turning(t_all *all, int i)
{
	double dir_x0;
	double plane_x0;

	dir_x0 = all->pl.dir_x;
	all->pl.dir_x = all->pl.dir_x * cos(i * TANGLE) - all->pl.dir_y * sin(i * TANGLE);
	all->pl.dir_y = dir_x0 * sin(i * TANGLE) + all->pl.dir_y * cos(i * TANGLE);
	plane_x0 = all->cam.plane_x;
	all->cam.plane_x = all->cam.plane_x * cos(i * TANGLE) - all->cam.plane_y * sin(i * TANGLE);
	all->cam.plane_y = plane_x0 * sin(i * TANGLE) + all->cam.plane_y * cos(i * TANGLE);
}

void ft_clean_img(t_all *all)
{
	int i;
	int j;
	char    *dst;

	i = 0;
	j = 0;
	while (i < all->win.y)
	{
		j = 0;
		while(j < all->win.x)
		{
			dst = all->img.addr + (i * all->img.line_length + j * (all->img.bits_per_pixel / 8));
			*(unsigned int*)dst = 0x000000;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win, all->img.img, 0, 0);
}

int key_press(int key, t_all *all)
{
	ft_clean_img(all);
	if (key == 13)
		ft_move_tb(all, 'W');
	else if (key == 0)
		ft_move(all, 'A');
	else if (key == 1)
		ft_move_tb(all, 'S');
	else if (key == 2)
		ft_move(all, 'D');
	else if (key == 53)
		exit(0);
	else if (key == 123)
		ft_turning(all, -1);
	else if (key == 124)
		ft_turning(all, 1);
	ft_screen(all);
	return (1);
}

void ft_begining_all(t_all *all, int save)
{
	int i = 0;
	int j = 0;

	all->save = save;
	all->tex.sp_buf = (double *)malloc(sizeof(double) * all->win.x + 1);
	all->win.mlx_ptr = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx_ptr, all->win.x, all->win.y, "game");
	all->img.img = mlx_new_image(all->win.mlx_ptr, all->win.x, all->win.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length , &all->img.endian);
	ft_screen(all);
	mlx_hook(all->win.win, 2, (1L << 0), &key_press, all);
	mlx_loop(all->win.mlx_ptr);
}
