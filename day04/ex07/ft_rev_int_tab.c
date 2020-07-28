#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int x[i];

	i = 0;
	x[i] = {0};
	while (i != size)
	{
		x[i] = tab[size - 1 - i];
		i++;
	}

	size = 0;
	while (size != i)
	{
		tab[size] = x[size];
		size++;
	}
}

