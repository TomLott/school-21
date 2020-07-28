#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main()
{
	int *a;
	int *b;
	int c;
	int d;

	c = 22;
	d = 4;
	a = &c;
	b = &d;

	ft_ultimate_div_mod(a,b);
	printf("%d\n %d\n", c, d);
}

