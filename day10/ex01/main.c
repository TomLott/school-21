#include <stdio.h>

int	*ft_range(int min, int max);

int main()
{
	int min = -100000;
	int max = 10000;
	int *range;
	int i = 0;
	range = ft_range(min, max);
	while (i < max -  min)
	{
		printf("%d, ", range[i]);
		i++;
	}
}

