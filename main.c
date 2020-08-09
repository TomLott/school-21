#include<stdio.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *characters_g;
char **massive;

int min(int a, int b, int c);

void ft_create_massive(char *argv, int att);

int ft_change(int **temp, int maxi, int maxj, int maxs);

void ft_translate(char **mas, char *ch);
{
	int 

int **find(char **massive, int row, int column) 
{ 
	int i;
   	int j;	
	char **temp; 
	int maxs;
	int maxi;
	int maxj;
	int k;	
 
   	ft_tranlate(massive, characters_g);	
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			temp[i][j] = massive[i][j];
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
		temp[i][0] = massive[i][0];
		i++;
	}
	j = 0;
	while(j < column)
	{
		temp[0][j] = massive[0][j];
		j++;
	}
	i = 1;
	while(i < row) 
	{
		j = 1;
		while (j < column) 
   		{
			if(massive[i][j] == 1)
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
	return (temp);
}

int ft_change(int **temp, int maxi, int maxj, int maxs)
{
	int i;
	int j;
	char buff;
	int row;
	int column;

	i = 0;
	j = 0;
	column = maxs;
	printf("%d colomn\n", column);
	printf("%d maxs\n", maxs);
	printf("%d\n", temp[maxi][maxj]);
   	while (i < maxs)
	{
		while(j < maxs)
		{
			temp[maxi][maxj] = -1;
			printf("%d\n", temp[maxj][maxi]); 
			maxi--;
			j++;
		}
		j = 0;
		maxi += column;
		maxj--;
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
	return (temp);
}

int min(int a, int b, int c) 
{ 
	int m = a;
	if (m > b)
		m = b; 
	if (m > c)
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
	characters[0] = '2';
	characters[1] = '0';
	characters[2] = '1';
	characters_g = malloc(sizeof(char)*3);
	i = 0;
	while (i < 3)
	{
		characters_g[i] = characters[i];
		i++;
	}
}

	 

char *ft_read(char *argv, int i)
{
	char buff[14];
	int file;
	int j;
	char c;
	char *temp;
	
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
	}
	return(buff);
}

char *proccesfirtsstring(char *argv, int i)
{
	int j;
	char *len;
	len = ft_read(argv, i);
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

void	ft_massive(int att, char buff[3000])
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
	ft_find(massive, att, i);
}


void ft_create_massive(char *argv, int att)
{
	char buff[3000];
	int file;
	char c;
	int j;
	int k;

	k = 0;
	printf("%d check\n", att);
	if((file = open(argv, O_RDONLY)) > 0)
	{
		while(read(file, &c, 1) > 0 && c != '\n')
		{
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		while (j < att - 1)
		{
			while(read(file, &buff,3000) > 0)
			{
				ft_massive(att, buff);
			}
			j++;
		}
	}
}

int main(int argc, char **argv) 
{
   	int file;
	char *attributes;
	int attrib;
	char **mas;
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		if(i < argc)
		{
			attributes = proccesfirtsstring(argv[i], i);
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
