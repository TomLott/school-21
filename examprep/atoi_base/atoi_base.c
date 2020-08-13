#include <unistd.h>
#include <stdio.h>


int nbr_inbase(char c, int base)
{
	if (base <= 10)
		return(c >= '0' && c <= '9');

	return((c >= '0' && c <= '9') || (c >= 'A' && (c <= 'A' + base - 10)) || (c >= 'a' && c <= ('a' + base - 10)));
}

int ft_atoi_base(const char *str, int base)
{
	int i;
	int nbr;
	int minus;
	char h;

	minus = 1;
	if(str[0] == '\0' || (base < 2 || base > 16))
			return(0);
	nbr = 0;
	i = 0;
	while(str[i] == '\t' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		minus = -minus;
		i++;
	}
	if (str[i] == '+')
		i++;
	while(str[i] != '\0' && nbr_inbase(str[i],base))
	{
		if(str [i] >= 'a' && 'f' >= str[i])
			nbr  = (nbr * base) + (str[i] - 'a' + 10);
		else if(str[i] >= 'A' && 'F' >= str[i])
		{
			h = str[i] + 32;
			nbr = (nbr * base) + (h - 'a' + 10);
		}
		else
			nbr = (nbr * base) + (str[i] - '0');
		i++;
	}
	return(nbr * minus);
}


int	main(int argc, char **argv)
{
	int  i = 16;

	printf("%d\n",ft_atoi_base(argv[1], i));
}
