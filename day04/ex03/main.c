#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int main()
{
	int a;
	int b;
	int c;
	int d;
	int *div;
	int *mod;

	a = 11;
	b = 2;
	c = 0;
	d = 0;
	div = &c;
	mod = &d;

	ft_div_mod(a, b, div, mod);
	printf("%d\n %d\n", c, d);
}
