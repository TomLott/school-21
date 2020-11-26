#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>


int ft_putchar_arg(const char *s, va_list factor, t_list *opt)
{
	int printed;

	printed = 0;
	if (*s == 's' && s++)
		printed = ft_print_str(opt, factor);
	else if ((*s == 'd' || *s == 'i') && s++)
		printed = ft_print_int(opt, factor);
	else if (*s == 'c' && s++)
		printed = ft_print_c(opt, factor);
	else if ((*s == 'x' || *s == 'X') && s++)
		printed = ft_print_x(opt, factor, *(s - 1));
	else if (*s == 'p' && s++)
		printed = ft_print_p(opt, factor);
	else if (*s == 'u' && s++)
		printed = ft_print_u(opt, factor);
	else
		printed = -1;
	return (printed);
}

static int		ft_print_width(t_list *l, int s_len, char *s)
{
	if (l->pres < 0 && s == NULL)
		l->pres = s_len;

}


int		ft_print_str(t_list *list, va_list factor)
{
	int i;
	char *str;
	int s_len;
	int printed;

	i = 0;
	s_len = 0;
	printed = 0;
	str = va_arg(factor, char *);
	s_len = (str) ? ft_strlen(str) : 6;
	printed = ft_print_width(list, s_len, printed);
	if (str == NULL) 
		str = ft_strdup("(null)");
	else if ((list->pres_exist && list->pres != 0) || !list->pres_exist)
	{

		while (str[i] && ((list->pres > 0) ? (i + 1 <= list->pres) : 1))
		{
			write(1, &str[i], 1);
			i++;
			printed++;
		}
	}
	printed += ft_print_width(list, s_len, printed);
	return (printed);
}
