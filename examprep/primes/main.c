#include <stdio.h>

int main()
{
	unsigned int i;
	unsigned int nb = 12;

	if (nb == 1)
		printf("1");
	else
	{
		i = 1;
		while (nb > 1)
		{
			i++;
			if (nb %  i == 0)
			{
				printf("%d", i);
				nb = nb / i;
				if (nb > 1)
					printf("*");
				i--;
			}
		}
	}
}
