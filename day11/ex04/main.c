#include <unistd.h>
#include <stdlib.h>
#include "ft_strs_to_tab.c"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}
void	ft_write(int nb)
{
	char i;
	if (nb != 0)
	{
		i = nb % 10 + '0';
		nb /= 10;
		ft_write(nb);
		write(1, &i, 1);
	}
}
void	ft_putnbr(int nb)
{
	if (nb != -2147483648 && nb != 0)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= (-1);
		}
		ft_write(nb);
	}
	else if (nb < 0)
		write(1, "-2147483648", 11);
	else
		write(1, "0", 1);
}
int main()
{
	char *toay[] = {"1aaaa", "2aaaa", "3aaaa", "SOaaa", "Ya", "World", "ws"};
    
    t_stock_str *to;
    
	int ac = 7;
	to = ft_strs_to_tab(ac, toay);
	int i = 0;
	while (i < ac + 1)
	{
		ft_putnbr(to->size);
		ft_putstr("\t");
		ft_putstr(to->str);
		ft_putstr("\t");
		ft_putstr(to->copy);
		ft_putstr("\n");
		i++;
		to++;
	}
}
