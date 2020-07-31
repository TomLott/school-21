#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int j;
	char *temp;
	char *temp2;
	int p;
	int lensep;
	int sepr;

	i = 0;
	j = 0;
	p = 0; // количество символов
	temp = *strs;
	while (j < size)
	{
		while (temp[j][i] != '\0')
		{
			i++;
			p++;
		}
		i = 0;
		j++;
	}
	j = 0;
	while (sep[lensep] != '\0')
	{
		lensep++;
	}
	temp2 = malloc(sizeof(char*) * p + sizeof(char) * lensep * (size - 1));
	p = 0;
	while (j < size)
	{
		sepr = 0;
		while (temp[j][i] != '\0')
		{
			temp2[p] = temp[j][i];
			p++;
			i++;
		}
		i = 0;
		j++;
		while (sep[sepr] != '\0')
		{
			temp2[p] = sep[sepr];
			p++;
			sepr++;
		}
	}
	*strs = temp2;
	return (*strs);
}
