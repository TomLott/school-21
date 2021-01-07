/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   purge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:41:32 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:41:34 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_free_map(char **s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != NULL)
		{
			free(s[i]);
			s[i] = NULL;
			i++;
		}
		free(s);
	}
}

void	ft_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	ft_clean_img(t_all *all)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (i < all->win.y)
	{
		j = 0;
		while (j < all->win.x)
		{
			dst = all->img.addr + (i * all->img.line_length
					+ j * (all->img.bits_per_pixel / 8));
			*(unsigned int*)dst = 0x000000;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(all->win.mlx_ptr, all->win.win, all->img.img, 0, 0);
}

void	ft_new_bzero(t_all **all)
{
	(*all)->cam.y = 0;
	(*all)->dist.wall_dist = 0;
}
