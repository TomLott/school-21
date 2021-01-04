#include "../includes/cub.h"

void bit_offset(unsigned char *head, unsigned int i)
{
	head[0] = (unsigned char)(i % 256);
	head[1] = (unsigned char)(i / 256 % 256);
	head[2] = (unsigned char)(i / 256 / 256 % 256);
	head[3] = (unsigned char)(i / 256 / 256 / 256);
}

int making_header(int fd, t_all *a, int size)
{
	unsigned char head[54];
	int file_size;

	ft_bzero(head,54);
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

void ft_buffer(unsigned char *buff, unsigned int i)
{
	buff[0] = (unsigned char)(i % 256);
	buff[1] = (unsigned char)(i / 256 % 256);
	buff[2] = (unsigned char)(i / 256 / 256 % 256);
	buff[3] = (unsigned char)(0);
}

int putting_data(int fd, t_all *a, int size)
{
	unsigned char buff[4];
	int x;
	int y;
	unsigned int *coord; /**coordinates*/

	ft_bzero(buff, 4);
	y = (a->win.y) * a->win.x;
	while(y >= 0)
	{
		x = 0;
		while(x < a->win.x)
		{
			coord = (unsigned int *)(a->img.img + y);
			//printf("%u\n", *coord);
			ft_buffer(buff, *coord);
			//write(1, buff, 4);
			write(fd, buff, 4);
			y++;
			x++;
		}
		y -= (2 * a->win.x);
	}
	return (1);
}

int taking_screenshot(t_all *a)
{
	int fd;
	int size;

	size = (4 - (a->win.x * 3) % 4) % 4;
	fd = open("screenshot.bmp", O_WRONLY| O_CREAT, 0777 | O_TRUNC | O_APPEND);
	making_header(fd, a, size);
	putting_data(fd, a, size);
	close(fd);
	return (1);
}

void ft_screenshot(t_all *all)
{
	write(1, "Making screenshot\n", 18);
	if (!(taking_screenshot(all)))
		ft_errormessage(-9);
	write(1, "Screenshot saved\n", 17);
	close_prog(all);
}