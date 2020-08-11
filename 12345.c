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
	i = 0;
	mas = (int*)malloc(sizeof(int) * column);
	if (mas != NULL)
	{
		while (i < column)
		{
			if (row[i] == ch)
				mas[i] = 0;
			else if(row[i] == characters_g[2])
				mas[i] = 1;
			i++;
		}
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

int **find(char **massive, int row, int column)
{
    int i;
       int j;
    int **temp;
    int maxs;
    int maxi;
    int maxj;
    int **temp2;

    i = 0;
    j = 0;
     
    temp2 = ft_translate(massive, row, column);
    temp = (int**)malloc(sizeof(int*)*row);
    while (i < row)
    {
        temp[i] = (int*)malloc(sizeof(int)*column);
        j = 0;
        while (j < column)
        {
            temp[i][j] = temp2[i][j];
            j++;
        }
        i++;
    }
    i = 1;
    while(i < row)
    {
        j = 1;
        while (j < column)
           {
            if(temp2[i][j] == 1)
                temp[i][j] = min(temp[i][j-1], temp[i-1][j], temp[i-1][j-1]) + 1;
            else
                temp[i][j] = 0;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < row)
    {
        j = 0;
        while(j < column)
        {
            printf("%d max ", temp[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    maxs = temp[0][0];
       maxi = 0;
    maxj = 0;
    i = 0;
    while (i < row)
    {
        j = 0;
        while(j < column)
        {
            if(maxs < temp[i][j])
            {
                maxs = temp[i][j];
                        maxi = i;
                    maxj = j;
               }
              j++;
        }
        i++;
    }
    printf("%d %d %d\n", maxs, maxi, maxj);
    i = 0;
    while (i < row)
    {
        j = 0;
        while(j < column)
        {
            printf("%d ", temp[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    printf("%d\n", temp[maxi][maxj]);
    ft_change(temp, maxi, maxj, maxs);
    ft_print(temp, row, column);
    return (temp);
}


void ft_print(int **temp, int row, int column)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while(i < row)
    {
        while(j < column)
        {
            if (temp[i][j] == 0)
                write(1, &characters_g[1], 1);
            else if(temp[i][j] == -1)
                write(1, &characters_g[0], 1);
            else
                write(1, &characters_g[2], 1);
            j++;
        }
        j = 0;
        write(1, "\n", 1);
        i++;
    }
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
	write(1, "char check", 10);
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
	if ((file = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while (read(file, &c, 1) > 0 && c != '\n')
		buff[j++] = c;
	buff[j] = '\0';
	ft_defining(buff, j);
	close(file);
	//else
		//exit(write(1, "map error\n", 10));
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
	write(1, "YOU!", 4);
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
	int i;

	i = -1;
	while(buff[++i] != '\0')
		if (buff[i] != characters_g[1] && buff[i] != characters_g[2] && buff[i] != '\n')
			return (0);
	return (1);
}

int		ft_massive(int att, char *buff)
{
	int	j;
	int	k;
	int	len;
	int	shit;

	shit = 1;
	j = -1;
	k = 0;
	write(1, "FUCKING!", 9);
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
	write(1, "YOU!", 4);
	write(1, "a", 1);
	find(massive, att, j - 1);
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
	write(1, "shitty", 7);
	temp = (char*)malloc(sizeof(char) * i + 1);
	if ((file = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while (read(file, &c, 1) > 0 && c != '\n')
		i = 0;
	while (read(file, &c, 1) > 0)
		temp[i++] = c;
	temp[i] = '\0';
	write(1, " ft_read 0 ", 10);
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
	write(1, " HATE ", 6); 
	if(temp[0] == '\0' || temp[0] == '\n')
		return(0);
	write(1, "DUMB", 4);
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
		printf("\n%d i\n", i);
		printf("%d max\n", max);
		printf("%d len\n", len);
		i = 0;
	}
	write(1, "after cicle", 11);
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
	write(1, "I", 1);
	while (temp[i++] != 0)
		if (temp[i] == '\n')
			counter++;
	if (counter != att || ft_valid(temp) == 0)
		return (0);
	write(1, "after counter", 14);
	if(ft_massive(att, temp) == 0 )
		return (0);
	close(file);
	return (1);
}

char	*create_file()
{
	char	str;
	int		h;
	char	*file;

	file = "our.txt";
	if ((h = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0600)) == -1)
		return (0);
	while (read(0, &str, 1))
		write(h, &str, 1);
	write(h, "\n", 1);
	close(h);
	return (file);
}

int	print_map(char *file)
{
	char	*attributes;
	int		attrib;

	if ((attributes = ft_read(file)) == NULL)
	{
		write(2,"map error", 10);
		return (0);
	}
	if (ft_charact_check(attributes) == 0)
	{
		write(2,"map error", 10);
		return (0);
	}
	else
		{
			attrib = ft_atoi(attributes); // тут считывание пошло не по плану:( поэтому снова атои
			if (ft_create_massive(file, attrib) == 0)
			{
				write(2, "map error", 10);
				return (0);
			}
		}
	return (1);
}

int		main(int argc, char **argv)
{
	char	*attributes;
	int		attrib;
	int		i;
	char	*file;

	i = 0;
	if (argc == 1)
	{
		file = create_file();
		write(1, "\n", 1);
		print_map(file);
	}
	else
		while (++i < argc)
		{
			print_map(argv[i]);
			write(1, "\n", 1);
		}
	return (0);
}