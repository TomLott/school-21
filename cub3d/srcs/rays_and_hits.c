#include "../includes/cub.h"
void            my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char    *dst;

	color = (all->ray.side == 1) ? 0x0FFFFF : color;
	dst = all->img.addr + (y * all->img.line_length + x * (all->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_text_colour(t_all *all, t_cam *c, t_dist *d, t_hight hig)
{
	int i = 0;
	int j = 0;

	while (hig.start < hig.end)
	{
		my_mlx_pixel_put(all, c->i, hig.start, 0x000FFF);
		hig.start++;
	}
}

void ft_hight(t_all *all, t_cam *c, t_dist *d)
{
	t_hight hig;

	ft_bzero(&hig, sizeof(t_hight));
	hig.h = all->win.x / 1.5;
	hig.hight = (int)(hig.h / d->wall_dist);
	hig.start = (int)(-hig.hight / 2 + hig.h / 2);
	if (hig.start < 0)
		hig.start = 0;
	hig.end = (int)(hig.hight / 2 + hig.h / 2);
	if (hig.end >= hig.h)
		hig.end = hig.h - 1;
	ft_text_colour(all, c, d, hig);
	/**while(hig.j < all->win.x)
	{
		ft_floor(all, c, d, &hig);
		hig.j++;
	}*/
}

void ft_hit(t_all *all, t_cam *c, t_dist *d)
{
	all->ray.side = 0;
	all->ray.hit = 0;
	while (all->ray.hit == 0)
	{
	//	printf("%c\n", all->map.table[c->map_y][c->map_x]);
		if (d->side_x < d->side_y)
		{
			d->side_x += d->delta_x;
			c->map_x += d->step_x;
			all->ray.side = 0;
		}
		else
		{
			d->side_y += d->delta_y;
			c->map_y += d->step_y;
			all->ray.side = 1;
		}
		if (all->map.table[c->map_y][c->map_x] == '1')
			all->ray.hit = 1;
	}
	if (all->ray.side == 0)
		d->wall_dist = (c->map_x - c->posX + (1 - d->step_x) / 2) / all->ray.x;
	else
		d->wall_dist = (c->map_y - c->posY + (1 - d->step_y) / 2) / all->ray.y;
	//printf("%d side\n", all->ray.side);
	//printf("%f dist\n", d->wall_dist);
	ft_hight(all, c, d);
}

void ft_step(t_all *all, t_cam *c, t_dist *d)
{
	if (all->ray.x < 0)
	{
		d->step_x = -1;
		d->side_x = (c->posX - c->map_x) * d->delta_x;
	}
	else
	{
		d->step_x = 1;
		d->side_x = (c->map_x + 1.0 - c->posX) * d->delta_x;
	}
	if (all->ray.y < 0)
	{
		d->step_y = -1;
		d->side_y = (c->posY - c->map_y) * d->delta_y;
	}
	else
	{
		d->step_y = 1;
		d->side_y = (c->map_y + 1.0 - c->posY) * d->delta_y;
	}
	ft_hit(all, c, d);
}


void ft_ray(t_all *all, t_cam *c, t_dist *d)
{
	c->map_x = (int)c->posX;
	c->map_y = (int)c->posY;
	if (all->ray.y == 0)
		d->delta_x = 0;
	else
	{
		if (all->ray.x == 0)
			d->delta_x = 1;
		else
			d->delta_x = fabs(1 / all->ray.x);
	}
	if (all->ray.x == 0)
		d->delta_y = 0;
	else
	{
		if (all->ray.y == 0)
			d->delta_y = 1;
		else
			d->delta_y = fabs(1 / all->ray.y);
	}
	all->ray.hit = 0;
	ft_step(all, c, d);
}

void ft_get_texture(t_tex *tex, t_all *all)
{


}

void ft_init(t_all *all, t_cam *cam, t_dist *dist)
{
	ft_get_texture(&all->tex, all);
	cam->i = 0;
	cam->posX = all->pl.x;
	cam->posY = all->pl.y;
	if (all->flag == 0)
	{
		all->cam.plane_y = 0;
		all->cam.plane_x = 0.66;
		all->flag = 1;
	}
	while (cam->i < all->win.x)
	{
		cam->x = 2 * cam->i / (double) all->win.x - 1;
		all->ray.x = all->pl.dir_x + cam->plane_x * cam->x; /** changed x and y*/
		all->ray.y = all->pl.dir_y + cam->plane_y * cam->x;
		ft_ray(all, cam, dist);
		cam->i++;
	}
}
void ft_new_bzero(t_all **all)
{
	(*all)->cam.y = 0;
	(*all)->dist.wall_dist = 0;
}

void ft_screen(t_all *all)
{
	ft_new_bzero(&all);
	ft_init(all, &all->cam, &all->dist);
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win, all->img.img, 0, 0);
}

