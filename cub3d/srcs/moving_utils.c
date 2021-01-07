/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:40:28 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:40:30 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		inside_map(double x, t_all *all, int i, double line)
{
	int c;

	c = all->map.table[(int)line][(int)x];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	if (i == 1)
		return (x < (int)ft_strlen(all->map.table[(int)(x)]) && x > 0) ? 1 : 0;
	if (i == 0)
		return (1);
	return (0);
}

int		can_do(int c)
{
	return (c == OK || c == 'N'
			|| c == 'W' || c == 'E' || c == 'S') ? 1 : 0;
}

int		ft_close(void **all)
{
	t_all **new;

	new = (t_all **)all;
	mlx_clear_window((*new)->win.mlx_ptr, (*new)->win.win);
	mlx_destroy_window((*new)->win.mlx_ptr, (*new)->win.win);
	exit(1);
}
