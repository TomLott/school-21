int ft_len(char *argv)
{
	int len;

	len = 0;
	while (argv[len] != '\0')
		len++;
	return (len);
}

int ft_recurs(char *nb)
{
	int i;
	int nbr;
	int len2;
	int kostil;
	
	i = 0;
	nbr = 0;
	len2 = ft_len(nb);
	kostil = len2 - 1;
	while(len2 > 0)
	{
		nbr = nbr + (nb[i] - '0') * 10 * (len2);
		len2--;
		i++;
	}
	return (nbr);
}

char ft_prep(char *argv, int i, int minus)
{
	char *buf;
	int b;

	b = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == ' ' || argv[i] == '+')
			i++;
		if (argv[i] == '-')
			i++;
			minus++;
		if (argv[i] >= '0'	&& argv[i] <= '9')
		{
			buf[b] = argv[i];
			b++;
			i++;
		}
		else
			return (0);
	}
	buf[b] = '\0';
	b = ft_recurs(buf);
	return (b);
}

int ft_atoi(char *argv)
{
	int i;
	int nb;
	int len;

	i = 0;
	nb = 0;
	len = ft_len(argv);
	nb = ft_prep(argv, i, nb);
	while (len >= 0)
	{
		nb = nb + nb * ((len + 1) * 10);
		len--;
	}
	return(nb);
}

int main(int argc, char **argv)
{
	int i;
	int nb1;
	int nb2;

	i = 0;

	nb1 = ft_atoi(argv[1]);
	nb2 = ft_atoi(argv[2]);
}	


