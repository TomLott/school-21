#include "../includes/cub.h"

int		ft_stringlen(t_all *all, char *line)
{
	int i;

	i = 0;
	while(*line)
	{
		if (*line == '0' || *line == '1' || *line == '2'
		|| *line == 'N' || *line == 'S' || *line == 'N'
		|| *line == 'E')
			i++;
		line++;
	}
	if (all->map.x && all->map.x != i)
		return (-1);
	return (i);
}

char *ft_map_making(char *line, t_all *all, int *i)
{
	char *temp;
	int j;

	j = 0;
	if (!(temp = malloc(sizeof(char) * (ft_stringlen(all, line) + 1))))
		return (NULL);
	while (line[*i])
	{
		if ((line[*i] == '0' || line[*i] == '1' || line[*i] == 'N'
		|| line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W'))
			temp[j++] = line[*i];
		else if (line[*i] != ' ')
		{
			free(temp);
			return (NULL);
		}
		else if (line[*i] != ' ')
		{
			temp[j++] = line[*i];
			all->map.sprite++;
		}
		(*i)++;
	}
	temp[j] = '\0';
	return (temp);
}
void ft_free(char **s)
{
	int i;

	i = 0;
	while(*s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	ft_map(t_all *all, char *line, int *i)
{
	char **map;
	int j;

	j = 0;
	all->err.x = 0;
	write(1, "map\n", 4);
	if (!(map = (char **)malloc(sizeof(char *) * (all->map.y + 2))))
		return (-1);
	while(j++ < all->map.y)
		map[j - 1] =all->map.table[j - 1];
	if (!(map[all->map.y] = ft_map_making(line, all, i)))
	{
		ft_free(map);
		return (-2);
	}
	map[all->map.y + 1] = NULL;
	if (all->map.y++ > 0)
		free(all->map.table);
	all->map.table = map;
	if ((all->map.x = ft_stringlen(all, line)) == -1)
		return (-3);
	return (1);
}