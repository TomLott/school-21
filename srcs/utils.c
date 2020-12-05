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

int ft_errormessage(int i)
{
	(i == -1) ? write(2, "Error: Can't allocate memory (malloc error)\n", 44) : 1;
	(i == -2) ? write(2, "Error: Invalid map\n", 19) : 1;
	(i == -3) ? write(2, "Error: Map should be rectangle\n", 31) : 1;
	return (-1);
}
