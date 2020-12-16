#include "../includes/cub.h"

int ft_resol(t_all *all, char *line, int *i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (line[*i] == 'R')
		(*i)++;
	ft_isspace(line, i);
	while(line[*i] >= '0' && line[*i] <= '9')
		x = x * 10 + (line[(*i)++] - '0');
	ft_isspace(line, i);
	while(line[*i] >= '0' && line[*i] <= '9')
		y = y * 10 + (line[(*i)++] - '0');
	mlx_get_screen_size(all->win.mlx_ptr, &all->win.x, &all->win.y);
	if (!(x > all->win.x))
		all->win.x = x;
	if (!(y >all->win.y))
		all->win.y = y;
	if (!all->win.y || !all->win.x)
		return (-4);
	return (0);
}

int line_parse(char *line, t_all *all)
{
	int i;

	i = 0;

	if (line[i] == 'R')
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
	else
		all->err.x = -8;
	ft_isspace(line, &i);
	if (all->err.x == 0 && line[i])
		all->err.x = -7;
	return (all->err.x < 0) ? ft_errormessage(all->err.x) : 0;
}

void ft_checking_each(char **table, t_all *all)
{
	int i;
	int j;
	char c;

	i = 0;
	while (table[i])
	{
		j = 0;
		while(table[i][j])
		{
			c = table[i][j];
			if (c != '0' && c != '2'
			&& c != 'W' && c != 'S' && c != 'N'
			&& c != 'E' && c != ' ' && c != '1')
				all->err.x = 2;
			j++;
		}
		i++;
	}
}



int	ft_parse(char *arg, t_all *all)
{
	char	*line;
	int		fd;
	t_list	*head;

	head = NULL;
	if ((fd = open(arg, O_RDONLY)) < 0)
	{
		write(2, "Error: Can't open file.", 23);
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	ft_purgatorium(all, &head);
	if (all->err.x < 0 || (all->err.x = ft_check_map(all)) == -2)
		return (ft_errormessage(-2));
	fd = 0;
	all->err.x = ft_player_parser(all, fd);
	return (all->err.x);
}