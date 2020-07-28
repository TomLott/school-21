#include <stdio.h>
#include <string.h>

int	ft_strcmp(char 	*s1, char *s2);

int main()
{
	char s1[] = "\200";
	char s2[] = "\0";

	printf("%d\n",ft_strcmp(s1,s2));
	printf("%d\n",strcmp(s1,s2));
}
