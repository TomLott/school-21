#include "ft_printf.h"
#include <unistd.h>

int ft_common_print(const char *s)
{
	if (*s == '%' && *(s + 1) == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
	{
		write(1, s, 1);
		return (0);
	}
}

int ft_check(const char s)
{
	if (s >= '0' && s<= '9')
		return (1);
	if (s == 'd' || s == 'x' || s == 's' 
			|| s == 'X' || s == 'c' || s == 'i'
			|| s == 'p' || s == 'u')
		return (1);
	if (s == '.' || s == '*' || s == '-')
		return (1);
	return (0);
}

int ft_check_pres(const char s, t_list *list)
{
	if (s >= '0' && s<= '9')
		return (1);
	if (s == '*')
		return (1);
	else if (s == 'd' || s == 'x' || s == 's' 
			|| s == 'X' || s == 'c' || s == 'i'
			|| s == 'p' || s == 'u')
	{
		list->pres_exist = -1;
		return (0);
	}
	list->pres_exist = 0;
	return (0);
}	
