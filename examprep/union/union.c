#include <stdio.h>
#include <unistd.h>

int check(char *str, char c, int j)
{
	int i = 0;

	while(i < j)
	{
		if (str[i] == c)
			return(0);
		i++;
	}
	return(1);
}




void ft_itra(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	while (str1[i] != '\0')
	{
		if (check(str1, str1[i], i) == 1)
		{
			while(str2[j] != '\0')
			{
				if (str2[j] == str1[i])
				{
					write(1, &str1[i], 1);
					break;
				}
				else
					j++;
			}
		}
		i++;
	}
}




int main(int argc, char **argv)
{
	ft_itra(argv[1], argv[2]);
}
	
