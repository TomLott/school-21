int	ft_power(int nb, int power, int res)
{
	while (power > 0)
	{
		res = res * nb;
		power--;
		ft_power(nb, power, res);
	}
	return (res);
}

int	ft_recursive_power(int nb, int power)
{
	int res;

	res = 1;
	if (power == 0 && nb == 0)
	{
		return (0);
	}
	if (power == 0 && nb < 0)
	{
		return (-1);
	}
	if (power < 0)
	{
		return (0);
	}
	return (ft_power(nb, power, res));
}
