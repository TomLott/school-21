#include "../includes/cub.h"

void ft_wallcast_n(t_all *all, t_cam *c, t_tex_n *n, t_hight *h)
{
	double step;
	double tex_p;
	unsigned int colour;
	int i;
	char *dst;


	h->tex_x = (int)(h->wall_x * (double)(n->x));
	if (all->ray.side == 0 && all->ray.x > 0)
		h->tex_x = n->x - h->tex_x - 1;
	if (all->ray.side == 1 && all->ray.y < 0)
		h->tex_x = n->x - h->tex_x - 1;
	i = h->start;
	step = 1.0 * n->x / h->hight;
	tex_p = (h->start - h->h / 2 + h->hight / 2) * step;
	while (i < h->end)
	{
		n->pos_y = (int)tex_p & (n->y - 1);
		tex_p += step;
		colour = *(unsigned int *)(n->addr + (n->pos_y) * n->x + h->tex_x);
		dst = all->img.addr + (i * all->img.line_length + c->i * (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = colour;
		i++;
	}
	h->start = h->end;
}

void ft_wallcast_e(t_all *all, t_cam *c, t_tex_e *n, t_hight *h)
{
	double step;
	double tex_p;
	unsigned int colour;
	int i;
	char *dst;

	h->tex_x = (int)(h->wall_x * (double)(n->x));
	if (all->ray.side == 0 && all->ray.x > 0)
		h->tex_x = n->x - h->tex_x - 1;
	if (all->ray.side == 1 && all->ray.y < 0)
		h->tex_x = n->x - h->tex_x - 1;
	i = h->start;
	step = 1.0 * n->x / h->hight;
	tex_p = (h->start - h->h / 2 + h->hight / 2) * step;
	while (i < h->end)
	{
		n->pos_y = (int)tex_p & (n->y - 1);
		tex_p += step;
		colour = *(unsigned int *)(n->addr + (n->pos_y) * n->x + h->tex_x);
		dst = all->img.addr + (i * all->img.line_length + c->i * (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = colour;
		i++;
	}
	h->start = h->end;
}

void ft_wallcast_s(t_all *all, t_cam *c, t_tex_s *n, t_hight *h)
{
	double step;
	double tex_p;
	unsigned int colour;
	int i;
	char *dst;

	h->tex_x = (int)(h->wall_x * (double)(n->x));
	if (all->ray.side == 0 && all->ray.x > 0)
		h->tex_x = n->x - h->tex_x - 1;
	if (all->ray.side == 1 && all->ray.y < 0)
		h->tex_x = n->x - h->tex_x - 1;
	i = h->start;
	step = 1.0 * n->x / h->hight;
	tex_p = (h->start - h->h / 2 + h->hight / 2) * step;
	while (i < h->end)
	{
		n->pos_y = (int)tex_p & (n->y - 1);
		tex_p += step;
		colour = *(unsigned int *)(n->addr + (n->pos_y) * n->x + h->tex_x);
		dst = all->img.addr + (i * all->img.line_length + c->i * (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = colour;
		i++;
	}
	h->start = h->end;
}

void ft_wallcast_w(t_all *all, t_cam *c, t_tex_w *n, t_hight *h)
{
	double step;
	double tex_p;
	unsigned int colour;
	int i;
	char *dst;

	h->tex_x = (int)(h->wall_x * (double)(n->x));
	if (all->ray.side == 0 && all->ray.x > 0)
		h->tex_x = n->x - h->tex_x - 1;
	if (all->ray.side == 1 && all->ray.y < 0)
		h->tex_x = n->x - h->tex_x - 1;
	i = h->start;
	step = 1.0 * n->x / h->hight;
	tex_p = (h->start - h->h / 2 + h->hight / 2) * step;
	while (i < h->end)
	{
		n->pos_y = (int)tex_p & (n->y - 1);
		tex_p += step;
		colour = *(unsigned int *)(n->addr + (n->pos_y) * n->x + h->tex_x);
		dst = all->img.addr + (i * all->img.line_length + c->i * (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = colour;
		i++;
	}
	h->start = h->end;
}