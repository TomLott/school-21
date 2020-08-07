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
int ft_count_if(char **tab, int length, int(*f)(char*));
int main()
{
	char *strs[4] = {"abba", "zabba", "gabba", "keba"};
	printf("%d", ft_count_if(strs, 4,  &contain_space));
	char *strs1[4] = { "abba", "za bba", "gabba beta", "be ta"};
	printf("%d", ft_count_if(strs1, 4, &contain_space));
	printf("\n03 - Right Answer");
}
