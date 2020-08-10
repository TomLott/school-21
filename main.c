#include<stdio.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *characters_g;
char **massive;

int min(int a, int b, int c);

void ft_create_massive(char *argv, int att);

int **ft_change(int **temp, int maxi, int maxj, int maxs);

void ft_print(int **temp, int row, int column);

int *ft_strdupint(char *row, int column, int *mas)
{
	int i;
	char ch;

	ch = characters_g[1]; 

	i = 0;
	mas = (int*)malloc(sizeof(int)*column);
	while (i < column)
	{

		if (row[i] == ch)
			mas[i] = 0;
		else
			mas[i] = 1;
		i++;
	}
	return(mas);
}

int **ft_translate(char **mas, int row, int column)
{
	int i;
	int j;
	int **massiveint;

	i = 0;
	j = 0;
	massiveint = (int**)malloc(sizeof(int*) * row);
	while(i < row)
	{
		massiveint[i] = ft_strdupint(mas[i], column, massiveint[i]);
		i++;
	}
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
	printf("\n");
	i = 0;
	while(i == 0)
	{
		temp[i][0] = temp2[i][0];
		i++;
	}
	j = 0;
	while(j < column)
	{
		temp[0][j] = temp2[0][j];
		j++;
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
			printf("%d ", temp[i][j]);
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


int **ft_change(int **temp, int maxi, int maxj, int maxs)
{
	int i;
	int j;
	int row;
	int column;

	i = 0;
	j = 0;
	row = maxj;
	column = maxi;
	printf("%d colomn a\n", column);
	printf("%d maxs\n", maxs);
	printf("%d last\n", temp[maxi][maxj]);
   	while (i < maxs)
	{
		while(j < maxs)
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
	i = 0;
	return (temp);
}

int min(int a, int b, int c) 
{ 
	int m = a;
	if (m > b)
		m = b; 
	else if (m > c)
		m = c; 
	return m; 
}

int	ft_atoi(char *buff)
{
	int i;
	int minus;
	int res;

	i = 0;
	minus = 0;
	res = 0;
	while(buff[i]  == ' ' || buff[i] == '\v' || buff[i] == '\t'
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
	printf("%d number\n",res);
	return(res);
}

int ft_strlen(char *buff)
{
	int i;

	i = 0;
	while(buff[i] != '\0')
		i++;
	return(i);
}
void ft_defining(char *buff, int j)
{
	int i;
	char *characters;
	int rows;

	i = 0;
	characters = malloc(sizeof(char)*3);

	write(1, &i, 1);
	while (i < 3)
	{
		characters[i] = buff[j-1];
		i++;
		j--;
	}
	buff[j] = '\0';
	printf("%s characters\n", characters);
	printf("%s left shit\n", buff);
	rows = ft_atoi(buff);

	characters_g = malloc(sizeof(char)*3);
	i = 0;
	while (i < 3)
	{
		characters_g[i] = characters[i];
		i++;
	}
}

	 

char *ft_read(char *argv)
{
	char *buff;
	int file;
	int j;
	char c;
	
	buff = (char*)malloc(sizeof(char)*14);
	j = 0;
	if ((file = open(argv, O_RDONLY)) > 0)
	{
		while(read(file, &c, 1) > 0 && c != '\n')
		{
			buff[j] = c;
			j++;
		}
		buff[j] = '\0';
		printf("%d\n", j);
		printf("%s oh shit! here we go again\n", buff);
		ft_defining(buff, j);
		close(file);
	}
	return(buff);
}

char *proccesfirtsstring(char *argv)
{
	char *len;
	len = ft_read(argv);
	return(len);
}

int ft_strlenspecial(char *buff)
{
	int i;

	i = 0;
	while(buff[i] >= 9 && buff[i] <= 126)
		i++;
	return(i);
}

char	*ft_strdup(char *src, int k)
{
	char	*tab;
	int		len;
	
	len = 0;
	while (src[len+k] != '\n')
	{
		len++;
	}
	tab = (char*)malloc(sizeof(char*) * len);
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

void	ft_massive(int att, char buff[65534])
{
	int i;
	int j;
	int k;
	int len;
	int shit = 1;

	i = 0;
	j = 0;
	k = 0;
	len = ft_strlenspecial(buff);
	massive = (char**)malloc(sizeof(char *)*att);	
	buff[len] = '\0';
	printf("%s\n", buff);
	while(j < att)
	{
		massive[j] = ft_strdup(buff,k);
		printf("%s\n",massive[j]);
		k = len/att * shit;
		shit++;
		j++;
	}
	i = len/att;
	find(massive, att, i);
}

char *ft_read_file(char *argv)
{
	int file;
	int i;
	char c;
	char *temp;

	i = 0;
	if ((file = open(argv, O_RDONLY))> 0)
	{
		while(read(file, &c, 1) > 0 && c != '\n')
			i = 0;
		while(read(file, &c, 1) > 0)
			i++;
		printf("%d all of \n", i);
	}
	temp = (char*)malloc(sizeof(char)*i+1);
	if ((file = open(argv, O_RDONLY))> 0)
	{
		while(read(file, &c, 1) > 0 && c != '\n')
			i = 0;
		while(read(file, &c, 1) > 0)
		{	
			temp[i] = c;
			i++;
		}
		printf("%d all of \n", i);
	}
	return (temp);
}

void ft_create_massive(char *argv, int att)
{
	char buff[65534];
	int file;
	char c;
	int j;
	char *temp;
	
	j = 0;
	printf("%d check\n", att);
	if((file = open(argv, O_RDONLY)) > 0)
	{	
		printf("%d amount\n", file);
		while(read(file, &c, 1) > 0 && c != '\n')
		{
			write(1, &c, 1);
			j++;
		}
		temp = ft_read_file(argv);
		printf("%s result\n", temp);
		ft_massive(att, temp);
		close(file);
	}
}

int main(int argc, char **argv) 
{
	char *attributes;
	int attrib;
	int i;

	i = 1;
	while (i < argc)
	{
		if(i < argc)
		{
			attributes = proccesfirtsstring(argv[i]);
			printf("%s\n",attributes);
			attrib = ft_atoi(attributes); // тут считывание пошло не по плану:( поэтому снова атои
			printf("%s\n",characters_g);
			printf("%d final result1\n",attrib); // тут уже INT
		}
		if(i< argc)
			ft_create_massive(argv[i], attrib);
		i++;
	}
}	
