#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *nbr)
{
	int i;
	int nb;
	int minus;

	nb = 0;
	i = 0;
	minus = 0;
	write(1, "here", 4);
	while(nbr[i] == ' ')
		i++;
	if(nbr[i] == '+')
		i++;
	if (nbr[i] == '-') 
	{
		minus = 1;
		i++;
	}
	while(nbr[i] >= '0' && nbr[i] <= '9')
	{
		nb = nb * 10 + nbr[i] - '0';
		i++;
	}
	if (minus == 1)
		nb = -nb;
	return (nb);
}

void ft_putnbr(int sum)
{
	int i;
	char c;

	i = 0;
	if (sum < 10)
	{
		c = sum + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(sum / 10);
		ft_putnbr(sum % 10);
	}

}
int	prime(int nb)
{
	int k;
	int i;

	k = 2;
	if (nb <= 1)
		return (0);
	while (nb % k != 0 && nb != k)
		k++;
	if (nb % k == 0 && nb == k)
		return (1);
	else
		return (0);
}
int	main(int argc, char **argv)
{ 
	int i;
	int nbr;
	int sum;
	
	i = 1;
	sum = 0;
	nbr = ft_atoi(argv[i]);
	while(nbr >  0)
	{
		if (prime(nbr) != 0)
			sum = sum + (nbr);
		nbr--;
	}
	ft_putnbr(sum);
}
