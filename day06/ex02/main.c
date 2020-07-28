#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int main()
{
	char dest[140]="hello ";
	char src[500] = "world";
	ft_strcat(dest,src);
//	printf("%s\n", strcat(dest, src));
	printf("%s\n", dest);
}
