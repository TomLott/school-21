/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begining.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:40:13 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:44:38 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_move_tb(t_all *all, int i)
{
	int n;

	n = (i == 'W') ? 1 : -1;
	if (inside_map((all->pl.x + n * all->pl.dir_x * MOVESPEED / 10), all, 0,
				(all->pl.y)) && can_do(all->map.table[(int)(all->pl.y)]
				[(int)(all->pl.x + n * all->pl.dir_x * MOVESPEED / 10)]))
		all->pl.x += (n * all->pl.dir_x * MOVESPEED / 10);
	if (inside_map((all->pl.y + n * all->pl.dir_y * MOVESPEED / 10), all,
				1, (all->pl.y)) && can_do(all->map.table[(int)
				(all->pl.y + n * all->pl.dir_y
				* MOVESPEED / 10)][(int)(all->pl.x)]))
		all->pl.y += (n * all->pl.dir_y * MOVESPEED / 10);
}

void	ft_move(t_all *all, int i)
{
	int n;

	n = (i == 'D') ? 1 : -1;
	if (inside_map((all->pl.x - n * all->pl.dir_y * MOVESPEED / 10), all,
				0, (all->pl.y)) && can_do(all->map.table[(int)(all->pl.y)]
				[(int)(all->pl.x - n * all->pl.dir_y * MOVESPEED / 10)]))
		all->pl.x -= (n * all->pl.dir_y * MOVESPEED / 10);
	if (inside_map((all->pl.y + n * all->pl.dir_x * MOVESPEED / 10), all,
				1, (all->pl.y)) &&
				can_do(all->map.table[(int)
				(all->pl.y + n * all->pl.dir_x * MOVESPEED / 10)]
				[(int)(all->pl.x)]))
		all->pl.y += (n * all->pl.dir_x * MOVESPEED / 10);
}

void	ft_turning(t_all *all, int i)
{
	double dir_x0;
	double plane_x0;

	dir_x0 = all->pl.dir_x;
	all->pl.dir_x = all->pl.dir_x * cos(i * TANGLE)
			- all->pl.dir_y * sin(i * TANGLE);
	all->pl.dir_y = dir_x0 * sin(i * TANGLE)
			+ all->pl.dir_y * cos(i * TANGLE);
	plane_x0 = all->cam.plane_x;
	all->cam.plane_x = all->cam.plane_x * cos(i * TANGLE)
			- all->cam.plane_y * sin(i * TANGLE);
	all->cam.plane_y = plane_x0 * sin(i * TANGLE)
			+ all->cam.plane_y * cos(i * TANGLE);
}

int		key_press(int key, t_all *all)
{
	if (key == 13)
		ft_move_tb(all, 'W');
	else if (key == 0)
		ft_move(all, 'A');
	else if (key == 1)
		ft_move_tb(all, 'S');
	else if (key == 2)
		ft_move(all, 'D');
	else if (key == 53)
		close_prog(all);
	else if (key == 123)
		ft_turning(all, -1);
	else if (key == 124)
		ft_turning(all, 1);
	ft_screen(all);
	return (1);
}

void	ft_begining_all(t_all *all, int save)
{
	all->save = save;
	if (!(all->tex.sp_buf = (double *)malloc(sizeof(double) * all->win.x + 1)))
		ft_errormessage(-1, all);
	all->win.mlx_ptr = mlx_init();
	all->win.win = mlx_new_window(all->win.mlx_ptr, all->win.x,
			all->win.y, "game");
	all->img.img = mlx_new_image(all->win.mlx_ptr, all->win.x, all->win.y);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
			&all->img.line_length, &all->img.endian);
	ft_screen(all);
	mlx_hook(all->win.win, 17, 0L, ft_close, &all);
	mlx_hook(all->win.win, 2, (1L << 0), &key_press, all);
	mlx_loop(all->win.mlx_ptr);
}
