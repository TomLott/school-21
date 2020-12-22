#include "../includes/cub.h"

void ft_wallcast_n(t_all *all, t_cam *c, t_tex_n *n, t_hight *h)
{
	double step;
	double tex_p;
	unsigned int colour;
	int i;

	i = h->start;
	step = 1.0 * n->y / h->hight;
	tex_p = (h->start - h->h / 2 + h->hight / 2) * step;
	while (i < h->end)
	{
		n->pos_y = (int)tex_p & (n->y - 1);
		tex_p += step;
		colour = *(unsigned int *)(n->addr + (n->pos_x * n->x)+  n->pos_x * (n->bits_per_pixel/8));
	}
}
