#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *ft_putnbr(int nbr, char *nb);
char *ft_itoa(int nbr);
int main()
{
	int nbr = -42150;
	ft_itoa(nbr);
}

char *ft_putnbr(int nbr, char *nb)
{
	int i = 0;
	int minus = 0;
	int j = 0;
	char c;


	if (nbr < 0)
	{
		minus = 1;
		nbr = -nbr;
	}
	while(nbr > 0)
	{
		nb[i] = nbr % 10 + '0';
		nbr = nbr/10;
		i++;
	}
	if (minus == 1)
		nb[i] = '-';
	while(j < i/2)
	{
		c = nb[j];
		nb[j] = nb[i];
		nb[i] = c;
		j++;
		i--;
	}
	i = 0;
	while(nb[i] != '\0')
		i++;
	nb[i] = '\0';
	printf("%s\n", nb);
	return(nb);
}

char *ft_itoa(int nbr)
{
	int i = 0;
	int temp = 0;
	char *nb;

	temp = nbr;
	if (temp < 0)
		temp = temp * -10;
	while(temp > 0)
	{
		temp = temp/10;
		i++;
	}
	nb = (char*)malloc(sizeof(char)*i+1);
	nb = ft_putnbr(nbr, nb);
	return(nb);
}

