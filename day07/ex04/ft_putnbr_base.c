#include <stdio.h>
int ft_len(char *base, int i)
{
	while (*(base + i) != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	int j;
	char s[100];

	i = 0;
	j = 0;
	i = ft_len(base, i);
	while (*(base + j) != 0)
	{
		s[j] = nb % i - '0';
		j++;
		printf("%d\n", s[j]);
	}
}
	

