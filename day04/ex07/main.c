#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int main()
{
	char str[]="hello!";
	int *tab;
	int size;

	size = 6;
	tab = &str;
	ft_rev_int_tab(tab, size);
	printf("%d\n %d\n", str, size);
}


