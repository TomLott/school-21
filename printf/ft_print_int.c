#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

static void    ft_putstr_fd(char *s, int fd)
{
    if (s)
        write(fd, s, ft_strlen(s));
}

static int  ft_length(int c, t_list *l)
{
    int len;

    len = 0;
	if (c == 0)
		return (1);
    if (c < 0)
	{
        c = -c;
		l->minus = 1;
	}
    while (c > 0)
    {
        len++;
        c = c / 10;
    }
    return (len);
}

static void    ft_putnbr_fd(int n, int fd, t_list *l)
{
    int temp;

	if (n == -2147483648)
        ft_putstr_fd("2147483648", fd);
    else if (n < 0)
    {
        ft_putchar_fd('-', fd);
        ft_putnbr_fd(-n, fd, l);
    }
    else if (n < 10)
        ft_putchar_fd(n + 48, fd);
    else
    {
        temp = n % 10 + 48;
        ft_putnbr_fd(n / 10, fd, l);
        ft_putchar_fd(temp, fd);
    }
}

static void	ft_print_width(t_list *l, int len, int printed, int res)
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

int		ft_print_int(t_list *l, va_list factor)
{
	int i;
	int res;
	int printed;
	int len;

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
	(res == 0 && l->pres == 0 && l->pres_exist != 0) ? 1 : (ft_putnbr_fd(res, 1, l));
	printed += len;
	if (l->flag == '-')
		while(l->width-- && ++printed)
			write(1, " ", 1);
	return (printed);
}
