#include "../includes/cub.h"

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
		|| line[*i] == 'E' || line[*i] == 'S' || line[*i] == 'W' || line[*i] == ' '))
			temp[j++] = line[*i];
		else if (line[*i] == '2')
		{
			temp[j++] = line[*i];
			all->map.sprite++;
		}
		/*else if (line[*i] != ' ')
		{
			free(temp);
			return (NULL);
		}*/
		(*i)++;
	}
	temp[j] = '\0';
	return (temp);
}

int zero_check(char **table, int i, int j)
{
	if (i < 0 || j < 0)
		return (0);
	write(1, "ss\n", 3);
	printf("%d %d\n", i, j);
	if (j + 2 > (int)ft_strlen(table[i - 1]) || j + 2 > (int)ft_strlen(table[i + 1]))
		return (0);
	if (!(table[i - 1][j] == '0' || table[i - 1][j] == '2'
			   || table[i - 1][j] == '1' || table[i - 1][j] == OK
			   || table[i - 1][j] == OK + 1 || table[i - 1][j] == 'W'
			   || table[i - 1][j] == 'S' || table[i - 1][j] == 'N' || table[i - 1][j] == 'E'))
		return (0);
	return (1);
}

int map_ok(int i, int j, t_all *a)
{
	if (a->map.table[i][j] != '1' && a->map.table[i][j] != OK
		&& a->map.table[i][j] != OK + 1)
	{
		if (zero_check(a->map.table, i, j) == 0)
			return (0);
		if (a->map.table[i][j] == '0')
			a->map.table[i][j] = OK;
		if (a->map.table[i][j] == '2')
			a->map.table[i][j] = OK + 1;
		if (!map_ok(i - 1, j, a) || !map_ok(i + 1, j, a)
		|| !map_ok(i, j - 1, a) || !map_ok(i, j + 1, a))
			return (0);
	}
	return (1);
}

int ft_check_map(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (all->map.table[i])
		printf("%s\n", all->map.table[i++]);
	i = 0;
	while(all->map.table[i])
	{
		j = 0;
		while(all->map.table[i][j])
		{
			if (all->map.table[i][j] == '0')
			{
				printf("%d %d %s\n", i, j, all->map.table[i]);
				if (!map_ok(i, j, all))
					return (-2); //map error;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_map(t_all *all, char *line, int *i)
{
	char **map;
	int j;

	*i = 0;
	j = 0;
	all->err.x = 0;
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
	if (all->map.y > 0)
		free(all->map.table);
	all->map.y++;
	j = 0;
	all->map.table = (char **)malloc(sizeof(char *) * (all->map.y + 1));
	while (j++ < all->map.y)
		all->map.table[j - 1] = map[j - 1];
	all->map.table[j] = NULL;
	//all->map.table = map;
//	j = 0;
	all->err.n = 1;
	//if (map)
	//	ft_free(map);
	return (1);
}