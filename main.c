#include<stdio.h> 
#include <fcntl.h>

int min(int a, int b, int c);
/*
int len(char **M);
{
	

char find(char **M) 
{ 
	int i;
   	int j;	
	char **temp; 
	int maxs;
	int maxi;
	int maxj;
	int k;	
  
	while (i < R)
	{
		j = 0;
		while (j < C)
		{
			temp[i][j] = M[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < R)
	{
		j = 0;
		while(j < C)
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
		temp[i][0] = M[i][0];
		i++;
	}
	j = 0;
	while(j < C)
	{
		temp[0][j] = M[0][j];
		j++;
	}
	i = 1;
	while(i < R) 
	{
		j = 1;
		while (j < C) 
   		{
			if(M[i][j] == 1)
				temp[i][j] = min(temp[i][j-1], temp[i-1][j], temp[i-1][j-1]) + 1;
			else
				temp[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < R)
	{
		j = 0;
		while(j < C)
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
	while (i < R) 
	{
		j = 0;
		while(j < C) 
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
	while (i < R)
	{
		j = 0;
		while(j < C)
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

int ft_change(int temp[R][C], int maxi, int maxj, int maxs)
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
	while (i < R)
	{
		j = 0;
		while(j < C)
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
*/
char *ft_read(char **argv)
{
	char len[3];
	char *file;

	file = open(argv, O_RDONLY)
	{
		if(len = read(file, &c, 1) > 0)
		{
			while(len != '\0')
			{
				len[j] = &c;
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
		printf("%s\n", len);
	}
	return(len);
}
	




int main(int argc, char **argv) 
{
   	char file;
	char attributes[3];
	char c;
	char **mas;
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < argc)
		attributes = ft_read(argv[i+1]);
	file = open(argv[1], O_RDONLY)
	{
		if(len = read(file, &c, 1) > 0)
		{
			while(len != '\0')
			{
				mas[i][j] = &c;
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	
	}
}	
