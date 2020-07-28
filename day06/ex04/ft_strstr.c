char	*ft_strstr(char	*str, char	*to_find)
{
	char *x;
	char *y;
	
	x = to_find;
	while (*(str) != '\0')
	{
		while(*str++ == *to_find++)
		{
			if (*to_find != '\0')
			{
				return (y);
			}
			if (*str == '\0')
			{
				return(0);
			}
		}
		to_find = x;
		y = str;
	}
	return(0);
}
