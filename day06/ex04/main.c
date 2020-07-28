#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int main()
{
	char str[] = "Hello my hel mine";
	char to_find[] = "lo";

	printf("%s\n", ft_strstr(str, to_find));
	printf("%s\n",strstr(str, to_find));
}
