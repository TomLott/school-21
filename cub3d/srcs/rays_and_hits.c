#include "../includes/cub.h"

void ft_text_colour(t_all *all, t_cam *c, t_dist *d, t_hight hig)
{
	int i = 0;
	int j = 0;
	while (i < hig.start)
	{
		mlx_pixel_put(all->win.mlx_ptr, all->win.win, i, 10 , 0x0FFFFF);
		i++;
	}
}

void ft_hight(t_all *all, t_cam *c, t_dist *d)
{
	t_hight hig;

	ft_bzero(&hig, sizeof(t_hight));
	hig.h = 10;
	hig.hight = (int)(hig.h / d->wall_dist);
	hig.start = -hig.hight / 2 + hig.h / 2;
	if (hig.start < 0)
		hig.start = 0;
	hig.end = (int)(hig.h / 2 + hig.h / 2);
	if (hig.end >= hig.h)
		hig.end = hig.h - 1;
	ft_text_colour(all, c, d, hig);
}

void ft_hit(t_all *all, t_cam *c, t_dist *d)
{
	while (all->ray.hit == 0)
	{
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
		if (all->map.table[c->map_x][c->map_y] > 0)
			all->ray.hit = 1;
	}
	if (all->ray.side == 0)
		d->wall_dist = c->map_x - c->posX + (1 - d->step_x) / 2 / all->ray.x;
	else
		d->wall_dist = c->map_y - c->posY + (1 - d->step_y) / 2 / all->ray.y;
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
		d->step_x = 1;
		d->side_x = (c->map_y + 1.0 - c->posY) * d->delta_y;
	}
	ft_hit(all, c, d);
}


void ft_ray(t_all *all, t_cam *c, t_dist *d)
{
	c->map_x = (int)c->posX;
	c->map_y = (int)c->posY;
	d->delta_x = fabs(1 / all->ray.x);
	d->delta_y = fabs(1 / all->ray.y);
	all->ray.hit = 0;
	ft_step(all, c, d);
}

void ft_init(t_all *all, t_cam *cam, t_dist *dist)
{
	int i;

	i = 0;
	cam->posX = all->pl.x;
	cam->posY = all->pl.y;
	cam->plane_x = 0;
	cam->plane_y = 0.66;
	while (i < all->win.x)
	{
		cam->x = 2 * i / (double) all->win.x - 1;
		all->ray.x = all->pl.dir_x + cam->plane_x * cam->x;
		all->ray.x = all->pl.dir_y + cam->plane_y * cam->y;
		ft_ray(all, cam, dist);
		i++;
	}
}

void ft_screen(t_all *all)
{
	t_cam	cam;
	t_dist	dist;

	ft_bzero(&cam, sizeof(t_cam));
	ft_bzero(&dist, sizeof(t_dist));
	ft_init(all, &cam, &dist);
}

