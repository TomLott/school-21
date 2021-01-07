/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_and_hits_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:41:54 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:41:56 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_text_colour(t_all *all, t_cam *c, t_hight hig)
{
	int		i;
	char	*dst;

	i = -1;
	while (++i < hig.start)
	{
		dst = all->img.addr + (i * all->img.line_length + c->i
				* (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = all->tex.c;
	}
	if (all->ray.side == 0 && (all->pl.x > all->ray.x + all->pl.x))
		ft_wallcast_e(all, c, &all->tex_e, &hig);
	else if (all->ray.side == 0)
		ft_wallcast_w(all, c, &all->tex_w, &hig);
	if (all->ray.side == 1 && (all->pl.y > all->ray.y + all->pl.y))
		ft_wallcast_n(all, c, &all->tex_n, &hig);
	else if (all->ray.side == 1)
		ft_wallcast_s(all, c, &all->tex_s, &hig);
	while (hig.end < all->win.y)
	{
		dst = all->img.addr + (hig.end * all->img.line_length + c->i
				* (all->img.bits_per_pixel / 8));
		*(unsigned int*)dst = all->tex.f;
		hig.end++;
	}
}

void	ft_hight(t_all *all, t_cam *c, t_dist *d)
{
	t_hight hig;

	ft_bzero(&hig, sizeof(t_hight));
	hig.h = all->win.y;
	hig.hight = (int)(hig.h / d->wall_dist);
	hig.start = (int)(-hig.hight / 2 + hig.h / 2);
	if (hig.start < 0)
		hig.start = 0;
	hig.end = (int)(hig.hight / 2 + hig.h / 2);
	if (hig.end >= hig.h)
		hig.end = hig.h - 1;
	if (all->ray.side == 0)
		hig.wall_x = c->posy + d->wall_dist * all->ray.y;
	else
		hig.wall_x = c->posx + d->wall_dist * all->ray.x;
	hig.wall_x -= floor(hig.wall_x);
	ft_text_colour(all, c, hig);
}

void	ft_hit(t_all *all, t_cam *c, t_dist *d)
{
	all->ray.side = 0;
	all->ray.hit = 0;
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
		if (all->map.table[c->map_y][c->map_x] == '1')
			all->ray.hit = 1;
	}
	if (all->ray.side == 0)
		d->wall_dist = (c->map_x - c->posx + (1 - d->step_x) / 2) / all->ray.x;
	else
		d->wall_dist = (c->map_y - c->posy + (1 - d->step_y) / 2) / all->ray.y;
	all->tex.sp_buf[c->i] = d->wall_dist;
	ft_hight(all, c, d);
}

void	ft_step(t_all *all, t_cam *c, t_dist *d)
{
	if (all->ray.x < 0)
	{
		d->step_x = -1;
		d->side_x = (c->posx - c->map_x) * d->delta_x;
	}
	else
	{
		d->step_x = 1;
		d->side_x = (c->map_x + 1.0 - c->posx) * d->delta_x;
	}
	if (all->ray.y < 0)
	{
		d->step_y = -1;
		d->side_y = (c->posy - c->map_y) * d->delta_y;
	}
	else
	{
		d->step_y = 1;
		d->side_y = (c->map_y + 1.0 - c->posy) * d->delta_y;
	}
	ft_hit(all, c, d);
}
