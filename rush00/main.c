#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *g_characters;

int		error(void)
{
	char *error;

	error = "map error\n";
	write(1, error, 10);
	return (0);
}

void	ft_free(char *str1, char **str2, int att)
{
	int i;

	i = 0;
	free(str1);
	while (i < att)
	{
		free(str2[i]);
		i++;
	}
	free(str2);
}

int		*ft_strdupint(char *row, int column, int *mas)
{
	int i;

	i = -1;
	if ((mas = (int*)malloc(sizeof(int) * column)) != NULL)
	{
		while (++i < column)
			if (row[i] == g_characters[1])
				mas[i] = 0;
			else if (row[i] == g_characters[2])
				mas[i] = 1;
	}
	return (mas);
}

int		**ft_translate(int row, int column, char **massive)
{
	int	i;
	int	**massiveint;

	i = -1;
	if ((massiveint = (int**)malloc(sizeof(int*) * row)) != NULL)
		while (++i < row)
			massiveint[i] = ft_strdupint(massive[i], column, massiveint[i]);
	return (massiveint);
}

void	ft_print(int **temp, int row, int column)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < row)
	{
		while (++j < column)
		{
			if (temp[i][j] == 0)
				write(1, &g_characters[1], 1);
			else if (temp[i][j] == -1)
				write(1, &g_characters[0], 1);
			else
				write(1, &g_characters[2], 1);
		}
		j = -1;
		write(1, "\n", 1);
	}
	i = 0;
	while (i++ < row)
		free(temp[i]);
	free(temp);
	free(g_characters);
}

int		**ft_change(int **temp, int maxi, int maxj, int maxs)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < maxs)
	{
		while (++j < maxs)
		{
			temp[maxi][maxj] = -1;
			maxj--;
		}
		j = -1;
		maxj += maxs;
		maxi--;
	}
	return (temp);
}

int		m(int a, int b, int c)
{
	if (a > b)
		a = b;
	else if (a > c)
		a = c;
	return (a);
}

int		max(int **t, int row, int column, int i)
{
	int	maxs;
	int	maxi;
	int	maxj;
	int	j;

	if (t == NULL)
		return (error());
	maxs = t[0][0];
	maxi = 0;
	maxj = 0;
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < column)
			if (maxs < t[i][j])
			{
				maxs = t[i][j];
				maxi = i;
				maxj = j;
			}
	}
	ft_change(t, maxi, maxj, maxs);
	ft_print(t, row, column);
	return (1);
}

void	find(int row, int column, int i, int **t2)
{
	int	j;
	int	**t;

	if ((t = (int**)malloc(sizeof(int*) * row)) != NULL)
	{
		while (++i < row)
		{
			j = -1;
			if ((t[i] = (int*)malloc(sizeof(int) * column)) != NULL)
				while (++j < column)
					t[i][j] = t2[i][j];
		}
		i = 0;
		while (++i < row)
		{
			j = 0;
			while (++j < column)
				if (t2[i][j] == 1)
					t[i][j] = m(t[i][j - 1], t[i - 1][j], t[i - 1][j - 1]) + 1;
				else
					t[i][j] = 0;
		}
		free(t2);
	}
	max(t, row, column, i);
}

int		ft_atoi(char *buff)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	minus = 0;
	res = 0;
	while (buff[i] == ' ' || buff[i] == '\v' || buff[i] == '\t'
			|| buff[i] == '\f' || buff[i] == '\n' || buff[i] == '\r')
		i++;
	if (buff[i] == '+')
		i++;
	if (buff[i] == '-')
	{
		minus = 1;
		i++;
	}
	while (buff[i] >= '0' && buff[i] <= '9')
	{
		res = res * 10 + buff[i] - '0';
		i++;
	}
	if (minus == 1)
		res = -res;
	return (res);
}

int		ft_charact_check(char *row)
{
	int	i;

	i = -1;
	while (row[++i])
	{
		if (row[0] == '0' || !(row[0] >= '1' && row[0] <= '9'))
			return (0);
		if (!(row[i] >= '0' && row[i] <= '9'))
			return (0);
	}
	if (g_characters[0] == g_characters[1]
		|| g_characters[1] == g_characters[2]
			|| g_characters[0] == g_characters[2])
		return (0);
	if ((g_characters[0] >= 0 && g_characters[0] < 32)
		|| (g_characters[1] >= 0 && g_characters[1] < 32)
			|| (g_characters[2] >= 0 && g_characters[2] < 32))
		return (0);
	return (1);
}

void	ft_defining(char *buff, int j)
{
	int		i;
	char	*characters;

	i = -1;
	if ((characters = (char*)malloc(sizeof(char) * 3)) != NULL)
	{
		while (++i < 3)
			characters[i] = buff[(j--) - 1];
		buff[j] = '\0';
	}
	if ((g_characters = (char*)malloc(sizeof(char) * 3)) != NULL)
	{
		i = -1;
		while (++i < 3)
			g_characters[i] = characters[i];
	}
}

char	*ft_read(char *argv)
{
	char	*buff;
	int		file;
	int		j;
	char	c;
	int		rd;

	j = 0;
	c = 0;
	file = 0;
	if ((buff = (char*)malloc(sizeof(char) * 14)) != NULL)
	{
		if ((file = open(argv, O_RDONLY)) == -1)
			return (NULL);
		while ((rd = read(file, &c, 1) > 0 && c != '\n') > 0)
			buff[j++] = c;
		if (rd < 0)
			return (NULL);
		buff[j] = '\0';
	}
	ft_defining(buff, j);
	close(file);
	return (buff);
}

int		ft_strlenspecial(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] >= 9 && buff[i] <= 126)
		i++;
	return (i);
}

char	*ft_strdup(char *src, int k)
{
	char	*tab;
	int		len;

	len = 0;
	while (src[len + k] != '\n')
		len++;
	if ((tab = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	len = 0;
	while (src[len + k] != '\n')
	{
		tab[len] = src[len + k];
		len++;
	}
	tab[len] = '\0';
	return (tab);
}

int		ft_final_check(char *buff)
{
	int	i;

	i = -1;
	while (buff[++i] != '\0')
		if (buff[i] != g_characters[1] &&
			buff[i] != g_characters[2] && buff[i] != '\n')
			return (0);
	return (1);
}

int		ft_massive(int att, char *buff, int j, int k)
{
	int		len;
	int		shit;
	int		**t2;
	char	**massive;

	shit = 1;
	j = -1;
	k = 0;
	len = ft_strlenspecial(buff);
	if ((massive = (char**)malloc(sizeof(char*) * att)) == NULL)
		return (0);
	while (++j < att)
	{
		massive[j] = ft_strdup(buff, k);
		k = len / att * shit;
		shit++;
	}
	if (ft_final_check(buff) == 0)
		return (0);
	j = len / att;
	t2 = ft_translate(att, j - 1, massive);
	k = -1;
	ft_free(buff, massive, att);
	find(att, j - 1, k, t2);
	return (1);
}

char	*ft_read_file(char *argv)
{
	int		file;
	int		i;
	char	c;
	char	*temp;

	i = 0;
	if ((file = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while (read(file, &c, 1) > 0 && c != '\n')
		i = 0;
	while (read(file, &c, 1) > 0)
		i++;
	close(file);
	temp = (char*)malloc(sizeof(char) * i + 1);
	if ((file = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while (read(file, &c, 1) > 0 && c != '\n')
		i = 0;
	while (read(file, &c, 1) > 0)
		temp[i++] = c;
	temp[i] = '\0';
	close(file);
	return (temp);
}

int		ft_valid(char *temp)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	len = 0;
	if (temp[0] == '\0' || temp[0] == '\n')
		return (0);
	while (temp[len + i] != '\0')
	{
		while (temp[len + i] != '\n')
			i++;
		if (max == 0)
			max = i;
		else if (i != max)
			return (0);
		len = len + i + 1;
		i = 0;
	}
	return (1);
}

int		ft_create_massive(char *argv, int att)
{
	int		file;
	char	*temp;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if ((file = open(argv, O_RDONLY)) == -1)
		return (0);
	temp = ft_read_file(argv);
	while (temp[i++] != 0)
		if (temp[i] == '\n')
			counter++;
	if (counter != att || ft_valid(temp) == 0)
		return (0);
	if (ft_massive(att, temp, i, i) == 0)
		return (0);
	close(file);
	return (1);
}

char	*create_file(void)
{
	char	str;
	int		h;
	char	*file;

	file = "our.txt";
	if ((h = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0600)) == -1)
		return (NULL);
	while (read(0, &str, 1))
		write(h, &str, 1);
	write(h, "\n", 1);
	close(h);
	return (file);
}

int		print_map(char *file)
{
	char	*attributes;
	int		attrib;

	if ((attributes = ft_read(file)) == NULL)
		return (0);
	if (ft_charact_check(attributes) == 0)
		return (0);
	else
	{
		attrib = ft_atoi(attributes);
		if (ft_create_massive(file, attrib) == 0)
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*file;

	i = 0;
	if (argc == 1)
	{
		file = create_file();
		write(1, "\n", 1);
		if (print_map(file) == 0)
			error();
	}
	else
		while (++i < argc)
		{
			if (print_map(argv[i]) == 0)
				error();
			if (i != (argc - 1))
				write(1, "\n", 1);
		}
	return (0);
}
