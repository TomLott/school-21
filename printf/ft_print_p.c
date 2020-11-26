#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

static int ft_length(size_t num, t_list *l)
{
    int i;
    int len;

    i = 0;
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

static int ft_put(size_t n, int printed, char x)
{
    int temp;

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


static void	ft_print_width(t_list *l, int len,  size_t res)
{
	int i;

	i = 0;
	if (l->pres < 0)
		l->pres = 0;
	if (l->flag == '0' && l->pres < 0)
	{
		l->pres = l->width;
		if (res < 0)
			l->pres--;
		l->width = 0;
	}
	if (l->pres > len && l->pres >= 0)
		l->pres = l->pres - len - l->minus;
	else if ((l->pres <= len + l->minus && l->pres >=0) || l->pres < 0)
		l->pres = 0;
//	if (res <= 0 && l->width)
//		l->width--;
	if (l->width > (len - l->minus + l->pres))
		l->width = l->width - l->pres - len;
	else if (l->width <= (len + l->pres))
		l->width = 0;
}


int		ft_print_p(t_list *l, va_list factor)
{
	int i;
	int printed;
	size_t res;
	int len;

	i = 0;
	len = 0;
	printed = 0;
	res = va_arg(factor, size_t);
	len = ft_length(res, l) + 2;
	ft_print_width(l, len, res);
	(!res && !l->pres && l->width && l->pres_exist) ? l->width++ : 1;
	while (l->flag != '-' && l->width-- > 0)
		write(1, " ", 1);
	if (!res && !l->pres && l->pres_exist == 1)
		write(1, "0x0", 3);
	else
	{
		write(1, "0x", 2);
		while (++i < l->pres && ++printed)
			write(1, "0", 1);
		printed += ft_put(res, printed, 'x');
	}
	while (l->flag == '-' && l->width-- > 0)
		write(1, " ", 1);
	return (printed);
}
