/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_and_hits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:41:45 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:41:48 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_ray(t_all *all, t_cam *c, t_dist *d)
{
	c->map_x = (int)c->posx;
	c->map_y = (int)c->posy;
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

void	ft_init(t_all *all, t_cam *cam, t_dist *dist)
{
	cam->i = 0;
	cam->posx = all->pl.x;
	cam->posy = all->pl.y;
	if (all->flag == 0)
		ft_cam_plane(all);
	while (cam->i < all->win.x)
	{
		cam->x = 2 * cam->i / (double)all->win.x - 1;
		all->ray.x = all->pl.dir_x + cam->plane_x * cam->x;
		all->ray.y = all->pl.dir_y + cam->plane_y * cam->x;
		ft_ray(all, cam, dist);
		cam->i++;
	}
	all->tex.sp_buf[all->win.x] = 0;
}

void	ft_cam_plane(t_all *all)
{
	if (all->pl.symbol == 'N')
	{
		all->cam.plane_y = 0;
		all->cam.plane_x = 0.66;
	}
	else if (all->pl.symbol == 'S')
	{
		all->cam.plane_x = -0.66;
		all->cam.plane_y = 0;
	}
	else if (all->pl.symbol == 'E')
	{
		all->cam.plane_x = 0;
		all->cam.plane_y = 0.66;
	}
	else if (all->pl.symbol == 'W')
	{
		all->cam.plane_x = 0;
		all->cam.plane_y = -0.66;
	}
	all->flag = 1;
}

void	ft_screen(t_all *all)
{
	ft_new_bzero(&all);
	if (all->save == 1)
		ft_screenshot(all);
	ft_init(all, &all->cam, &all->dist);
	ft_sprite(all);
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win, all->img.img, 0, 0);
}
