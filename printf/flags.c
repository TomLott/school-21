#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_len(t_list *temp)
{
	int i;
	
	i = 0;
	i = temp->flag_len + temp->width_len + temp->pres_len;
	if (temp->pres_exist == 1 || (temp->pres_exist == -1 && temp->width))
		i++;
	return (i);
}

char ft_flags(const char *str, t_list *temp)
{
	char	c;
	int		i;

	i = 0;
	c = 0;
	if (*str == '0')
	{
		c = *str;
		temp->flag_len = 1;
		return(c);
	}
	while (str[i] == '-')
	{
		c = str[i++];
		temp->flag_len = i;
	}
	return (c);
}

int		ft_pres(const char *str, va_list factor, t_list *temp)
{
	int i;
	int res;
	int minus;

	i = 0;
	res = 0;
	minus = 1;
	if (*str == '*')
	{
		res = va_arg(factor, int);
		temp->pres_len = 1;
		temp->pres_exist = 1;
		return (res);
	}
	if (*str == '-' && str++)
		minus = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		temp->pres_len = i;
	}
	temp->pres_len = (minus == -1) ? temp->pres_len++ : temp->pres_len;
	temp->pres_exist = 1;
	return (minus == -1) ? -res : res;
}

int		ft_width(const char *str, va_list factor, t_list *temp)
{
	int i;
	int res;
	int minus;

	i = 0;
	res = 0;
	minus = 1;
	if (*str == '*')
	{
		res = va_arg(factor, int);
		temp->width_len = 1;
		temp->flag = ((res < 0) ? '-' : temp->flag);
		return (res < 0) ? -res : res;
	}
	if (*str == '-' && str++)
		minus = -1;
	while (str[i] >= '0' && str[i]  <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		temp->width_len = i;
	}
	temp->width_len = (minus == -1) ? temp->width_len++ : temp->width_len;
	return (res * minus);
}
