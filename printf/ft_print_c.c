#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static int ft_print_width(t_list *list, va_list factor, int printed)
{
	int i;

	i = 0;
	if (list->flag == '-' && printed != 0)
	{
		while (i < list->width)
		{
			write(1, " ", 1);
			i++;
			printed++;
		}
	}
	else if (printed != 0 && list->width)
	{
		while (i < list->width)
		{
			write(1, " ", 1);
			i++;
			printed++;
		}
	}
	return (printed);
}	

int		ft_print_c(t_list *list, va_list factor)
{
	int i;
	int c;
	int printed;

	printed = 0;
	i = 0;
	if (!(c = va_arg(factor, int)))
	{
		write(1, "", 1);
		return (0);
	}
	printed = ft_print_width(list, factor, printed);
	write(1, &c, 1);
	printed++;
	printed += ft_print_width(list, factor, printed);
	return (printed);
}
