#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(int size,char **strs, char *sep);

int main()
{
	int size = 5;
	char **strs = {"Hello", "World"};
	char sep[1] = ",";

	ft_strjoin(size, strs, sep);

}
