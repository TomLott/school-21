#include "../includes/cub.h"

int ft_resol(t_all *all, char *line, int *i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_isspace(line, i);
	write(1, "inside resolution\n", 18);
	while(line[*i] >= '0' && line[*i] <= '9')
		x = x * 10 + (line[*i++] - '0');
	ft_isspace(line, i);
	while(line[*i] >= '0' && line[*i] <= '9')
		y = y * 10 + (line[*i++] - '0');
	mlx_get_screen_size(all->win.mlx_ptr, &x, &y);
	all->win.x = x;
	all->win.y = y;
	if (!all->win.y || !all->win.x)
		return (-4);
	return (0);
}

int line_parse(char *line, t_all *all)
{
	int i;

	i = 0;
	ft_isspace(line, &i);
	if (line[i] == '1' || all->err.x == 1)
		all->err.x = ft_map(all, line, &i);
	else if (line[i] == 'R')
		all->err.x = ft_resol(all, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->err.x = ft_texture(all, line, &i, &all->tex.s);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->err.x = ft_texture(all, line, &i, &all->tex.n);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		all->err.x = ft_texture(all, line, &i, &all->tex.w);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		all->err.x = ft_texture(all, line, &i, &all->tex.e);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		all->err.x = ft_texture(all, line, &i, &all->tex.item);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		all->err.x = ft_colour(line, &i, all);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		all->err.x = ft_colour(line, &i, all);
	ft_isspace(line, &i);
	if (all->err.x == 0 && line[i])
		all->err.x = -7;
	return (all->err.x < 0) ? ft_errormessage(all->err.x) : 0;
}

int	ft_parse(char *arg, t_all *all)
{
	char *line;
	int fd;
	int i;

	i = 0;
	if ((fd = open(arg, O_RDONLY)) < 0)
	{
		write(2, "Error: Can't open file.", 23);
		return (-1);
	}
	write(1, "2\n", 2);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (line_parse(line, all) < 0)
			i = -1;
		free(line);
	}
	close(fd);
	return (0);
}