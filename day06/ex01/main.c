#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
	char s1[] = "Hello";
	char s2[] = "eel";
	int n = 3;

	printf("%d\n",strncmp(s1,s2,n));
	printf("%d\n",ft_strncmp(s1,s2,n));
}
