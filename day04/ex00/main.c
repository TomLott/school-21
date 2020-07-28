#include <unistd.h>

void ft_ft(int *nbr);

int main()
{
	int x;
 	int *ptr;

	x = 5;
	ptr=&x;
	ft_ft(ptr);
	printf("%d\n",x);
	printf("%d\n",*ptr);
}
