#include "../includes/cub.h"

int line_parse(char *line, t_all *all)
{
	int i;

	ft_isspace(line, &i);
	write(1, "1\n", 2);
	if (line[i] == '1' || all->err->x == 1)
		all->err->x = ft_map(all, line, &i);
	write(1, "ss\n", 3);
	if (all->err->n < 0)
		return (ft_errormessage(all->err->n));
	return (0);
}

int	ft_parse(char *arg, t_all *all)
{
	char *line;
	int fd;
	int i;

	i = 0;
	write(1, "finish\n", 7);
	if ((fd = open(arg, O_RDONLY)) < 0)
	{
		write(2, "Error: Can't open file.", 23);
		return (-1);
	}
	write(1, "2\n", 2);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		write(1, "abab\n", 5);
		if (line_parse(line, all) < 0)
			i = -1;
		free(line);
	}
	close(fd);
	return (0);
}