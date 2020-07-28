#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str);

int main()
{
	char str[10] = "h\0lo";

	printf("%lu\n", strlen(str));
	printf("%d\n", ft_strlen (str));
}
