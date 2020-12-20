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
void ft_move_tb(t_all *all, int i)
{
	int n;

	n = (i == 'W') ? 1 : -1;
	all->pl.x += n * all->pl.dir_x * MOVESPEED/10;
	if (all->map.table[(int)(all->pl.y)][(int)(all->pl.x)] == '1')
		all->pl.x += (n * all->pl.dir_x * MOVESPEED/10);
	all->pl.y += n * all->pl.dir_y * MOVESPEED/10;
	if (all->map.table[(int)(all->pl.y)][(int)(all->pl.x)] == '1')
		all->pl.y -= (n * all->pl.dir_y * MOVESPEED/10);
/*	if (all->map.table[(int)(all->pl.x)][(int)(all->pl.y)] == '2')
	{
		all->map.table[(int)(all->pl.x)][(int)(all->pl.x)] = '0';
		all->map.sprite--;
	}*/
	//printf("move\n");
}

void ft_move(t_all *all, int i)
{
	int n;

	n = (i == 'D') ? 1 : -1;
	all->pl.x -= n * all->pl.dir_y * MOVESPEED/10;
	if (all->map.table[(int)(all->pl.y)][(int)(all->pl.x)] == '1')
		all->pl.x += (n * all->pl.dir_x * MOVESPEED/10);
	all->pl.y += n * all->pl.dir_x * MOVESPEED/10;
	if (all->map.table[(int)(all->pl.y)][(int)(all->pl.x)] == '1')
		all->pl.y -= (n * all->pl.dir_y * MOVESPEED/10);
/*	if (all->map.table[(int)(all->pl.x)][(int)(all->pl.y)] == '2')
	{
		all->map.table[(int)(all->pl.x)][(int)(all->pl.x)] = '0';
		all->map.sprite--;
	}*/
//	printf("move\n");
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
	//printf("%f %f turning\n", all->pl.dir_x, all->pl.dir_y);
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
	//printf("%f %f key_pres\n", all->pl.x, all->pl.y);
	//printf("%f %f key_pres rot\n", all->pl.dir_x, all->pl.dir_y);
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
