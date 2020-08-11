#include<stdio.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *characters_g;
char **massive;

int min(int a, int b, int c);

int ft_create_massive(char *argv, int att);

int **ft_change(int **temp, int maxi, int maxj, int maxs);

void ft_print(int **temp, int row, int column);

int		*ft_strdupint(char *row, int column, int *mas)
{
	int i;
	char ch;

	ch = characters_g[1];
	i = -1;
	mas = (int*)malloc(sizeof(int) * column);
	if (mas != NULL)
	{
	while (++i < column)
		if (row[i] == ch)
			mas[i] = 0;
		else
			mas[i] = 1;
	}
	return (mas);
}

int		**ft_translate(char **mas, int row, int column)
{
	int	i;
	int	**massiveint;

	i = -1;
	massiveint = (int**)malloc(sizeof(int*) * row);
	while(++i < row)
		massiveint[i] = ft_strdupint(mas[i], column, massiveint[i]);
	return(massiveint);
}

void	find(char **massive, int row, int column) 
{ 
	int i;
   	int j;	
	int **temp; 
	int maxs;
	int maxi;
	int maxj;

	temp = ft_translate(massive, row, column);	
	i = 0;
	while(++i < row) 
	{
		j = 0;
		while (++j < column)
			if(temp[i][j] == 1)
				temp[i][j] = min(temp[i][j-1], temp[i-1][j], temp[i-1][j-1]) + 1;
			else
				temp[i][j] = 0;
	}
	maxs = temp[0][0];
   	maxi = 0;
	maxj = 0;
	i = -1;
	while (++i < row)
	{
		j = -1;
		while(++j < column)
			if(maxs < temp[i][j])
    		{
				maxs = temp[i][j];
				maxi = i;
				maxj = j;
			}
	}
	ft_change(temp, maxi, maxj, maxs);
	ft_print(temp, row, column);
}

void	ft_print(int **temp, int row, int column)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < row)
	{
		while (j < column)
		{
			if (temp[i][j] == 0)
				write(1, &characters_g[1], 1);
			else if (temp[i][j] == -1)
				write(1, &characters_g[0], 1);
			else
				write(1, &characters_g[2], 1);
			j++;
		}
		j = 0;
		write(1, "\n", 1);
		i++;
	}
	free(temp);
}

int		**ft_change(int **temp, int maxi, int maxj, int maxs)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < maxs)
	{
		while (j < maxs)
		{
			temp[maxi][maxj] = -1;
			maxj--;
			j++;
		}
		j = 0;
		maxj += maxs;
		maxi--;
		i++;
	}
	return (temp);
}

int		min(int a, int b, int c)
{
	if (a > b)
		a = b;
	else if (a > c)
		a = c;
	return (a);
}

int		ft_atoi(char *buff)
{
	int i;
	int minus;
	int res;

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

int ft_charact_check(char *row)
{
	int i;
	
	i = 0;
	while(row[i])
	{
		if (row[0] == '0' || !(row[0] >= '1' && row[0] <= '9'))
			return(0);
		if (!(row[i] >= '0' && row[i] <= '9'))
			return (0);
		i++;
	}
	if (characters_g[0] == characters_g[1] 
		|| characters_g[1] == characters_g[2]
			||characters_g[0] == characters_g[2])
		return (0);
	return(1);
}

void	ft_defining(char *buff, int j)
{
	int		i;
	char	*characters;

	i = -1;
	characters = (char*)malloc(sizeof(char) * 3);
	while (++i < 3)
		characters[i] = buff[(j--) - 1];
	buff[j] = '\0';
	characters_g = (char*)malloc(sizeof(char) * 3);
	i = -1;
	while (++i < 3)
		characters_g[i] = characters[i];
}

char	*ft_read(char *argv)
{
	char	*buff;
	int		file;
	int		j;
	char	c;

	j = 0;
	c = 0;
	buff = (char*)malloc(sizeof(char) * 14);
	if ((file = open(argv, O_RDONLY)) > 0)
	{
		while (read(file, &c, 1) > 0 && c != '\n')
			buff[j++] = c;
		buff[j] = '\0';
		ft_defining(buff, j);
		close(file);
	}
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
	tab = (char*)malloc(sizeof(char) * len);
	if (tab == NULL)
		return (NULL);
	len = 0;
	while (src[len + k] != '\n')
	{
		tab[len] = src[len + k];
		len++;
	}
	return (tab);
}
int	ft_final_check(char *buff)
{
	int i;

	i = 0;
	while(buff[i] != '\0')
	{
		if (buff[i] != characters_g[1] && buff[i] != characters_g[2] && buff[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_massive(int att, char *buff)
{
	int	j;
	int	k;
	int	len;
	int	shit;

	shit = 1;
	j = -1;
	k = 0;
	len = ft_strlenspecial(buff);
	massive = (char**)malloc(sizeof(char*) * att);
	if (!(massive == 0))
	{
		buff[len] = '\0';
		while (++j < att)
		{
			massive[j] = ft_strdup(buff, k);
			k = len / att * shit;
			shit++;
		}
	}
	if (ft_final_check(buff) == 0)
			return (0);
	j = len / att;
	find(massive, att, j);
	return(1);
}

char	*ft_read_file(char *argv)
{
	int		file;
	int		i;
	char	c;
	char	*temp;

	i = 0;
	if ((file = open(argv, O_RDONLY)) > 0)
	{
		while (read(file, &c, 1) > 0 && c != '\n')
			i = 0;
		while (read(file, &c, 1) > 0)
			i++;
		close(file);
	}
	temp = (char*)malloc(sizeof(char) * i + 1);
	if ((file = open(argv, O_RDONLY)) > 0)
	{
		while (read(file, &c, 1) > 0 && c != '\n')
			i = 0;
		while (read(file, &c, 1) > 0)
			temp[i++] = c;
		close(file);
	}
	return (temp);
}

int ft_valid(char *temp)
{
	int i;
	int max;
	int len;

	i = 0;
	max = 0;
	len = 0;
	if(temp[0] == '\0' || temp[0] == '\n')
		return(0);
	while(temp[len + i]!= '\0')
	{
		while(temp[len + i] != '\n')
			i++;
		if (max == 0)
			max = i;
		else 
			if (i != max)
				return(0);
		len = len + i + 1;
		i = 0;
	}
	return (1);
}

int		ft_create_massive(char *argv, int att)
{
	int		file;
	char	*temp;
	int i;
	int counter;

	i = 0;
	counter = 0;
	if ((file = open(argv, O_RDONLY)) > 0)
	{
		temp = ft_read_file(argv);
		while (temp[i++] != 0)
		{
			if (temp[i] == '\n')
				counter++;
		}
		if ((ft_valid(temp) == 0) || counter != att)
			return (0);
		if(ft_massive(att, temp) == 0 )
			return (0);
		close(file);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*attributes;
	int		attrib;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (i < argc)
		{
			attributes = ft_read(argv[i]);
			if (ft_charact_check(attributes) == 0)
				write(2,"map error", 10);
			else
			{
				attrib = ft_atoi(attributes); // тут считывание пошло не по плану:( поэтому снова атои
				if (ft_create_massive(argv[i], attrib) == 0)
					write(2,"map error", 10);
			}
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
