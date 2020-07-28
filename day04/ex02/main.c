#include <stdio.h>

void ft_swap(int *a, int *b);

int main()
{
	int *a;
	int *b;
	int c;
	int d;

	c = 5;
	d = 10;
	a = &c;
	b = &d;

	ft_swap(a, b);
	printf("%d\n %d\n", c,d);
}
