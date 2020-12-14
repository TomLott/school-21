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

int key_press(int key, t_all *all)
{
	mlx_clear_window(all->win.mlx_ptr, all->win.win);
	printf("%f %f key_pres\n", all->pl.y, all->pl.x);
	if (key == 13)
	{
		all->pl.y -= 1;
	} else if (key == 1)
	{
		all->pl.y += 1;
	} else if (key == 0)
		all->pl.x -= 1;
	else if (key == 2)
		all->pl.x += 1;
	else if (key == 53)
		exit(0);
	else if (key == 123)
	{
		all->pl.dir_x -= 0.05;
		all->pl.dir_y += 0.05;
	} else if (key == 124)
	{
		all->pl.dir_y -= 0.05;
		all->pl.dir_x += 0.05;
	}
	ft_screen(all);
	return (1);
}
/*
void ft_player_draw(t_all *all, t_point point)
{
	float c;
	float x;
	float y;
	int k;
	int l;

	c = 0;
	printf("%f %f player\n", all->pl.y, all->pl.x);
	while (c < 100)
	{
		x = all->pl.x + c * cos(all->pl.dir);
		y = all->pl.y + c * sin(all->pl.dir);
		k = (int)x/SCALE;
		l = (int)y/SCALE;
		if (all->map.table[k/SCALE][l/SCALE] != ' ')
			break ;
		point.x = x;
		point.y = y;
		mlx_pixel_put(all->win.mlx_ptr, all->win.win, point.x, point.y, 0x0FFFFF);
		c++;
	//	size_t pix_x = x * 100;
		//size_t pix_y = y * 100;
	}
}*/
/*
void ft_draw_screen(t_all *all)
{
	t_point point;

	ft_bzero(&point, sizeof(t_point));
	while (all->map.table[point.y])
	{
		point.x = 0;
		while (all->map.table[point.y][point.x])
		{
			if (all->map.table[point.y][point.x] == '1')
				ft_scale_img(&all->win, point, 0xFFFFFF);
			point.x++;
		}
		point.y++;
	}
	ft_player_draw(all, point);
}*/

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
