/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parcer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:41:23 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:41:25 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_player_parser(t_all *all, int i)
{
	char	c;
	int		j;
	int		counter;

	i = 0;
	counter = 0;
	while (i < all->map.y && ++i)
	{
		j = 0;
		while (j < (int)(ft_strlen(all->map.table[i - 1])) && ++j)
		{
			c = all->map.table[i - 1][j - 1];
			if ((c == 'N' || c == 'W' || c == 'E' || c == 'S') && ++counter)
			{
				all->pl.symbol = c;
				all->pl.y = (double)i - 0.1;
				all->pl.x = (double)j - 0.1;
				all->pl.dir_x = (c == 'E' || c == 'W') ? 1 : 0;
				all->pl.dir_y = (c == 'S' || c == 'N') ? 1 : 0;
				all->pl.dir_x *= (c == 'W') ? -1 : 1;
				all->pl.dir_y *= (c == 'N') ? -1 : 1;
			}
		}
	}
	return (counter != 1) ? (-7) : 0;
}
