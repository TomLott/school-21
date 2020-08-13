#include <unistd.h>
#include <stdio.h>

int main ()
{
	int i;
	int nb1= 42;
	int nb2 = 12;
	int res;

	i = nb2;
	while(i <= nb2)
	{
		if (nb1%i == 0 && nb2%i == 0)
		{
			printf("%d\n", i);
			return(i);
		}
		i--;
	}	
	printf("%d", i);
}
