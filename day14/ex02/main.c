#include <stdio.h>
int		contain_space(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			return (1);
		str++;
	}
	return (0);
}
int ft_any(char **tab, int(*f)(char*));
int main()
{
	char *strs[4] = {"abba", "zabba", "gabba", NULL};
	printf("%d", ft_any(strs, &contain_space));
	char *strs1[4] = {"abba", "zabba", "gabba beta", NULL};
	printf("%d", ft_any(strs1, &contain_space));
	printf("\n01 - Right Answer");
}
