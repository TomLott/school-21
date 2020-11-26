#include "ft_printf.h"
#include <unistd.h>

static int  ft_length(unsigned int c, t_list *l)
{
    int len;

    len = 0;
	if (c == 0)
		return (1);
    if (c < 0)
	{
		l->minus = 1;
        c = -c;
	}
    while (c > 0)
    {
        len++;
        c = c / 10;
    }
    return (len);
}

static  int    ft_putnbr_fd_u(unsigned int n, int fd, int printed)
{
    unsigned int temp;

	temp = 0;
    if (n < 10)
	{
        ft_putchar_fd(n + 48, fd);
		printed++;
	}
    else
    {
        temp = n % 10 + 48;
        ft_putnbr_fd_u(n / 10, fd, printed);
        ft_putchar_fd(temp, fd);
    }
	return (printed);
}

static void  ft_print_width(t_list *l, int len, int printed, int res)
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

int ft_print_u(t_list *l, va_list factor)
{
    int 			i;
    unsigned int	res;
    int				printed;
    int				len;

    i = -1;
    printed = 0;
    res = va_arg(factor, int);
    len = ft_length(res, l);
	ft_print_width(l, len, printed, res);
    if (l->flag != '-')
        while (l->width-- > 0 && ++printed)
            write(1, " ", 1);
    (res < 0) ? write(1, "-", 1) : 1;
    res = (res < 0) ? (-res) : res;
    while(++i < l->pres && ++printed)
        write(1, "0", 1);
    (res == 0 && l->pres == 0 && l->pres_exist != 0) ? 1 : ft_putnbr_fd_u(res, 1, printed);
    printed += len;
	if (l->flag == '-')
        while(l->width-- && ++printed)
            write(1, " ", 1);
    return (printed);
}
