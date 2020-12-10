#include "../includes/cub.h"
int ft_colour_atoi(char *line, int *i)
{
	int res;
	int minus;

	res = 0;
	minus = 1;
	if (line[*i] == ',')
		(*i)++;
	if (line[*i] == '-' && (*i)++)
		minus = -1;
	while (line[*i] >= '0' && line[*i] <= '9')
		res = res * 10 + (line[(*i)++] - 48);
	return (res * minus);
}


int ft_colour(char *line, int *i, t_all *all)
{
	int r;
	int g;
	int b;
	char texture;

	texture = line[*i];
	(*i)++;
	ft_isspace(line, i);
	r = ft_colour_atoi(line, i);
	ft_isspace(line, i);
	g = ft_colour_atoi(line, i);
	ft_isspace(line, i);
	b = ft_colour_atoi(line, i);
	ft_isspace(line, i);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0 || line[*i] != '\0')
		return (-6);
	if (texture == 'F')
		all->tex.f = (r << 16) + (g << 8) + b;
	else if (texture == 'C')
		all->tex.c = (r << 16) + (g << 8) + b;
	return (0);
}

int ft_xmp_check(t_all *all, char *filename, unsigned int **x)
{
	int fd;
	int mas[5];
	int i;
	char *img;

	i = 0;
	fd = 0;
	img = NULL;
	while (mas[i])
		mas[i++] = 0;
	if (!file_format(filename, ".xmp"))
		return (-1);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	img = mlx_xpm_file_to_image(all->win.mlx_ptr, filename,
									   &mas[0], &mas[1]);
	if (!img)
		return (-1);
	*x = (unsigned int *)mlx_get_data_addr(all->win.img, &mas[2], &mas[3], &mas[4]);
	return (0);
}


int ft_texture(t_all *all, char *line, int *i, unsigned int **x)
{
	int k;
	char *filename;
	(*i) = (*i) + 2;
	ft_isspace(line, i);
	k = (*i);
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(filename = (char *)malloc(sizeof(char) * (*i - k + 1))))
		return (-1);
	*i = k;
	k = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		filename[k++] = line[(*i)++];
	filename[k] = '\0';
	k = ft_xmp_check(all, filename, x);
	free(filename);
	return (k == -1 ? -5 : 0);
}

