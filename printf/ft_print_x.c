#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static int ft_length(long num, t_list *l)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		l->minus = 1;
	}
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return(i);
}
static int ft_put(long n, int printed, char x)
{
	int	temp;

	if (n < 10 && ++printed)
	{
		temp = n + 48;
		write(1, &temp, 1);
	}
	else if ((n < 16 && n >= 10) && ++printed)
	{
		temp = (x == 'x') ? ( n + 87) : (n + 55);
		ft_putchar_fd((char)temp, 1);
	}
	else
	{
		temp = ((n % 16) < 10) ? n % 16 + 48 : ((x == 'x') ? (n % 16 + 87) : (n % 16 + 55));
		printed +=ft_put(n/16, printed, x);
		ft_putchar_fd(temp, 1);
	}
	return (printed);
}

static void ft_print_width(t_list *l, int len, int printed, int res)
{
    if (l->flag == '0' && l->pres < 0)
    {
        l->pres = l->width;
        if (res < 0 && l->pres != 0)
            l->pres--;
    }
    if (l->flag == '0' && !l->pres_exist)
    {
        l->pres = l->width - l->minus;
        l->width = 0;
    }
    if (l->pres > len && l->pres >= 0)
        l->pres -= len;
    else if (l->pres <= len && l->pres > 0)
        l->pres = 0;
    if (res < 0 && l->width)
        l->width--;
    if (l->width > len + l->pres)
        l->width = l->width - len - l->pres;
    else if (l->width <= len + l->pres)
        l->width = 0;
    if (l->pres == 0 && l->pres_exist != 0 && res == 0 && l->width != 0)
        l->width++;
}

int		ft_print_x(t_list *l, va_list factor, char x)
{
	int i;
	long res;
	int printed;
	int len;
	
	i = -1;
	printed = 0;
	res = va_arg(factor, long);
	len = ft_length(res, l);
    ft_print_width(l, len, printed, res);
    if (l->flag != '-')
        while (l->width-- > 0 && ++printed)
            write(1, " ", 1);
    (res < 0) ? write(1, "-", 1) : 1;
    res = (res < 0) ? (-res) : res;
    while(++i < l->pres && ++printed)
        write(1, "0", 1);
    (res == 0 && l->pres == 0 && l->pres_exist != 0) ? 1 : (ft_put(res, printed, x));
    printed += len;
    if (l->flag == '-')
        while(l->width-- && ++printed)
            write(1, " ", 1);
	return (printed);
}
