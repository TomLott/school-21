#include "../includes/cub.h"

int	file_format(char *s, char *format)
{
	int i;
	int j;

	i = ft_strlen(s) - 1;
	j = ft_strlen(format) - 1;
	if (j >= i)
		return (0);
	while (j > 0)
	{
		if (s[i] != format[j])
			return(0);
		j--;
		i--;
	}
	return (1);
}

int	ft_isspace(char *line, int *i)
{
	while (line[*i] == '\t' || line[*i] == '\n' || line[*i] =='\v'
		|| line[*i] == '\r' || line[*i] == '\f' || line[*i] == ' ')
		(*i)++;
	return (1);
}

void ft_free(char **s)
{
	int i;

	i = 0;
	while(s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int ft_errormessage(int i)
{
	(i == -1) ? write(2, "Error: Can't allocate memory (malloc error)\n", 44) : 1;
	(i == -2) ? write(2, "Error: Invalid map\n", 19) : 1;
	(i == -3) ? write(2, "Error: Map should be rectangle\n", 31) : 1;
	(i == -4) ? write(2, "Error: Invalid resolution\n", 26) : 1;
	(i == -5) ? write(2, "Error: Invalid image(textures)\n", 31) : 1;
	(i == -6) ? write(2, "Error: Invalid colour\n", 22) : 1;
	(i == -7) ? write(2, "Error: extra line/symbols in file\n", 34) : 1;
	(i == -8) ? write(2, "Error\n one or few parametres is missing or invalid for some reason\n", 67) : 1;
  	return (-1);
}

int		ft_stringlen(t_all *all, char *line)
{
	int i;

	i = 0;
	while(*line)
	{
		if (*line == '0' || *line == '1' || *line == '2'
			|| *line == 'N' || *line == 'S' || *line == 'W'
			|| *line == 'E')
			i++;
		line++;
	}
	//if (all->map.x && all->map.x != i)
	//	return (-1);
	return (i);
}
