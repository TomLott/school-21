#include "../includes/cub.h"
/**
unsigned int ft_colour_ch(t_all *all, unsigned int color)
{
	char i;
	if (all->ray.side == 0 && all->pl.x > all->pl.dir_x + all->pl.x)
		i = 'n';
	else if (all->ray.side == 0)
		i = 's';
	if (all->ray.side == 1 && all->pl.y > all->pl.dir_y + all->pl.y)
		color = 'w';
	else if (all->ray.side)
		color = 'e';
}*/

void            my_mlx_pixel_put(t_all *all, int x, int y, t_hight *h)
{
	char    *dst;
	unsigned color;

	//color = (all->ray.side == 1) ? 0x32CD32 : color;
//	color = ft_colour_ch(all, color);
	dst = all->img.addr + (y * all->img.line_length + x * (all->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void ft_text_colour(t_all *all, t_cam *c, t_dist *d, t_hight hig)
{
	int i = 0;
	char    *dst;


	while (i < hig.start)
	{
		dst = all->img.addr + (i * all->img.line_length + c->i * (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = all->tex.c;
		i++;
	}
	if (all->ray.side == 0 && (all->pl.x > all->pl.dir_x + all->pl.x))
		ft_wallcast_n(all, c, &all->tex_n, &hig);
	else if (all->ray.side == 0)
		ft_wallcast_s(all, c, &all->tex_s, &hig);
	if (all->ray.side == 1 && (all->pl.y > all->pl.dir_y + all->pl.y))
		ft_wallcast_w(all, c, &all->tex_w, &hig);
	else if (all->ray.side == 1)
		ft_wallcast_e(all, c, &all->tex_e, &hig);
	while (hig.end < all->win.y)
	{
		dst = all->img.addr + (hig.end * all->img.line_length + c->i * (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = all->tex.f;
		hig.end++;
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
	if (all->ray.side == 0)
		hig.wall_x = c->posY + d->wall_dist * all->ray.y;
	else
		hig.wall_x = c->posX + d->wall_dist * all->ray.x;
	hig.wall_x -= floor(hig.wall_x);
	//printf("%f in higth\n", hig.wall_x);
	ft_text_colour(all, c, d, hig);


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

