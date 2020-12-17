#include "../includes/cub.h"
void ft_rays_hits(t_all *all)
{
	t_ray ray;
	t_hit hit;

	all->ray = ray;
	all->hit = hit;
	ray.x = 0;
	ray.y = 0;
	hit.x = 0;
	hit.y = 0;
	ft_screen(all);
}

void ft_scale_img(t_win *win, t_point point, int colour)
{
	t_point max;

	max.x = (point.x + 1) * SCALE;
	max.y = (point.y + 1) * SCALE;
	point.x *= SCALE;
	point.y *= SCALE;
	while (point.y < max.y)
	{
		while (point.x < max.x)
			mlx_pixel_put(win->mlx_ptr, win->win, point.x++, point.y, colour);
		point.x -= SCALE;
		point.y++;
	}
}

void ft_move(t_all *all, int i)
{
	int n;

	n = (i == 'W' || i == 'D') ? 1 : -1;
	all->pl.x -= n * all->pl.dir_y * MOVESPEED;
	if (all->map.table[(int)(all->pl.x)][(int)(all->pl.y)] == '1')
		all->pl.x += n * all->pl.dir_y * MOVESPEED;
	all->pl.y += n * all->pl.dir_x * MOVESPEED;
	if (all->map.table[(int)(all->pl.x)][(int)(all->pl.y)] == '1')
		all->pl.y += n * all->pl.dir_x * MOVESPEED;
	if (all->map.table[(int)(all->pl.x)][(int)(all->pl.y)] == '2')
	{
		all->map.table[(int)(all->pl.x)][(int)(all->pl.x)] = '0';
		all->map.sprite--;
	}
}

void ft_turning(t_all *all, int i)
{
	double hyp;

	if (i == 123)
	{
		all->pl.dir_x = all->pl.dir_x * cos(0.05)
						- all->pl.dir_y * sin(0.05);
		all->pl.dir_y = all->pl.dir_y * cos(0.05)
						+ all->pl.dir_x * sin(0.05);
		hyp = hypot(all->pl.dir_x, all->pl.dir_y);
		all->pl.dir_x /= hyp;
		all->pl.dir_y /= hyp;
	}
	else
	{
		all->pl.dir_x = all->pl.dir_x * cos(-TURNANGLE)
						- all->pl.dir_y * sin(-TURNANGLE);
		all->pl.dir_y = all->pl.dir_y * cos(-TURNANGLE)
						+ all->pl.dir_x * sin(-TURNANGLE);
		hyp = hypot(all->pl.dir_x, all->pl.dir_y);
		all->pl.dir_x /= hyp;
		all->pl.dir_y /= hyp;
	}
	printf("%f %f turning\n", all->pl.dir_x, all->pl.dir_y);
}

int key_press(int key, t_all *all)
{
	mlx_clear_window(all->win.mlx_ptr, all->win.win);
	printf("%f %f key_pres\n", all->pl.x, all->pl.y);
	printf("%f %f key_pres rot\n", all->pl.dir_x, all->pl.dir_y);
	if (key == 13)
		ft_move(all, 'W');
	else if (key == 0)
		ft_move(all, 'A');
	else if (key == 1)
		ft_move(all, 'S');
	else if (key == 2)
		ft_move(all, 'D');
	else if (key == 53)
		exit(0);
	else if (key == 123)
		ft_turning(all, 123);
	else if (key == 124)
		ft_turning(all, 124);
	ft_screen(all);
	return (1);
}

void ft_begining_all(t_all *all)
{
	all->win.mlx_ptr = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx_ptr, all->win.x, all->win.y, "game");
	all->img.img = mlx_new_image(all->win.mlx_ptr, all->win.x, all->win.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length , &all->img.endian);
	ft_screen(all);
	mlx_hook(all->win.win, 2, (1L << 0), &key_press, all);
	mlx_loop(all->win.mlx_ptr);

}
