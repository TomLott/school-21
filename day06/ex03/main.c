#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
	char dest[15] = "Hello ";
	char src[15] = "world";
	unsigned int nb = 2;

	ft_strncat(dest, src, nb);
	printf("%s\n", dest);
}
