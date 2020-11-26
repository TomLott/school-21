#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

t_list *ft_restart(t_list *options)
{
	options->flag = 0;
	options->width = 0;
	options->pres = 0;
	options->flag_len = 0;
	options->width_len = 0;
	options->pres_len = 0;
	options->pres_exist = 0;
	options->minus = 0;
	return (options);
}


size_t  ft_strlen(const char *string)
{
    char    *temp;
    size_t  i;

    temp = (char *)string;
    i = 0;
    while (temp[i] != '\0')
        i++;
    return (i);
}

int		ft_strlen_int(int num)
{
	int len;

	len = 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char    *ft_strdup(const char *s1)
{
    size_t  i;
    char    *str;

    i = 0;
    while (s1[i])
        i++;
    if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (s1[i] != '\0')
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}


t_list	*ft_choise(const char *s, int i, va_list factor)
{
	t_list *temp;
	i++;
	int res;
	int len;

	len = 0;
	temp = (t_list *)malloc(sizeof(t_list));
	temp = ft_restart(temp);
	temp->flag = ft_flags(s + i, temp);
	i += temp->flag_len;
	temp->width = ft_width((s + i), factor, temp);
	(temp->width < 0) ? temp->flag = '-' : 1;
	(temp->width < 0) ? temp->width = -temp->width : 1;
	i += temp->width_len;
	if (s[i] == '.' && ft_check_pres(s[i + 1], temp) && i++)
		temp->pres = ft_pres((s + i), factor, temp);
	i = (temp->pres_exist == -1) ? i++ : i;
	i = (s[i - 1] == '*') ? i : i + ft_strlen_int(temp->pres);
	temp->len = ft_len(temp);
	return (temp);
}

int ft_work(va_list factor, const char *s)
{
	int i;
	t_list *opt;
	int printed;
	int temp;

	i = 0;
	printed = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			opt = ft_choise(s, i, factor);
			i += opt->len + 1;
			if ((temp = ft_putchar_arg((s + i), factor, opt)) == -1)
				return (-1);
			printed += temp;
		}
		else
		{
			write(1, &s[i], 1);
			printed++;
		}
		i++;
	}
	return(printed);
}


int ft_printf(const char *s, ...)
{
	va_list factor;
	int		counter;

	va_start(factor, s);
	counter = ft_work(factor, s);
	va_end(factor);
	return (counter);
}
/*
int main()
{
//	ft_printf("%0*.*s hihi %020.*i %010c", 12, 3, "world", 10, -14, 'b');
//	ft_printf("\n");
//	printf("%d\n", ft_printf("%015.10x\n", -110));
//	ft_printf("%10.10p\n", "aaa");
//	ft_printf("%u\n", -100);
}*/
