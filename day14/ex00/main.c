#include <stdio.h>

#include <unistd.h>


void	ft_foreach(int *tab, int length, void(*f)(int));


void	ft_reverse(int nb)
{
	char x;

	if (nb != 0)
	{
		x = nb % 10 + '0';
		nb = nb / 10;
		ft_reverse(nb);
		write(1, &x, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb != -2147483648 && nb != 2147483647 && nb != 0)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		ft_reverse(nb);

	}
}

int main()
{
	int length;
	int tab[3] = {1, 2, 3};
	void (*ptr)(int);

	ptr = &ft_putnbr;
	ft_foreach(tab, 3, &ft_putnbr);
	return(0);
}


