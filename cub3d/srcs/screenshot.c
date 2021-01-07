/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:42:01 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:42:03 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	bit_offset(unsigned char *head, unsigned int i)
{
	head[0] = (unsigned char)(i % 256);
	head[1] = (unsigned char)(i / 256 % 256);
	head[2] = (unsigned char)(i / 256 / 256 % 256);
	head[3] = (unsigned char)(i / 256 / 256 / 256);
}

int		making_header(int fd, t_all *a)
{
	unsigned char	head[54];
	int				file_size;

	ft_bzero(head, 54);
	file_size = 54 + (a->win.x * a->win.y * 4);
	head[0] = (unsigned char)('B');
	head[1] = (unsigned char)('M');
	bit_offset(head + 2, file_size);
	head[10] = (unsigned char)(54);
	head[14] = (unsigned char)(40);
	bit_offset(head + 18, a->win.x);
	bit_offset(head + 22, a->win.y);
	head[26] = (unsigned char)(1);
	head[28] = (unsigned char)(32);
	return (!(write(fd, head, 54) < 0));
}

int		putting_data(int fd, t_all *a)
{
	unsigned char	buff[4];
	int				y;
	int				line_length;

	ft_bzero(buff, 4);
	y = a->win.y;
	line_length = a->win.x * a->img.bits_per_pixel / 8;
	while (y >= 0)
	{
		write(fd, (unsigned char *)(a->img.addr + y
		* a->img.line_length), line_length);
		y--;
	}
	return (1);
}

int		taking_screenshot(t_all *a)
{
	int fd;

	ft_init(a, &a->cam, &a->dist);
	ft_sprite(a);
	if (!(fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777 | O_TRUNC | O_APPEND)))
		return (0);
	making_header(fd, a);
	putting_data(fd, a);
	close(fd);
	return (1);
}

void	ft_screenshot(t_all *all)
{
	write(1, "Making screenshot\n", 18);
	if (!(taking_screenshot(all)))
		ft_errormessage(-9, all);
	write(1, "Screenshot saved\n", 17);
	close_prog(all);
}
