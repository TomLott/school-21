/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:53:25 by itollett          #+#    #+#             */
/*   Updated: 2020/11/30 18:10:19 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length(long num, t_list *l)
{
	int i;

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
	return (i);
}

static void	ft_put(long n, t_list *l, char x)
{
	int	temp;

	if (n < 10)
	{
		temp = n + 48;
		write(1, &temp, 1);
		l->digit_len++;
	}
	else if (n < 16 && n >= 10)
	{
		temp = (x == 'x') ? (n + 87) : (n + 55);
		ft_putchar_fd((char)temp, 1, l);
	}
	else
	{
		if (n % 16 < 10)
			temp = n % 16 + 48;
		else
			temp = (x == 'x') ? (n % 16 + 87) : (n % 16 + 55);
		ft_put(n / 16, l, x);
		ft_putchar_fd(temp, 1, l);
	}
}

static void	ft_print_width(t_list *l, int len, int res)
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

int			ft_print_x(t_list *l, va_list factor, char x)
{
	int		i;
	long	res;
	int		printed;
	int		len;

	i = -1;
	printed = 0;
	res = va_arg(factor, long);
	len = ft_length(res, l);
	ft_print_width(l, len, res);
	if (l->flag != '-')
		while (l->width-- > 0 && ++l->digit_len)
			write(1, " ", 1);
	(res < 0) ? write(1, "-", 1) && ++l->digit_len : 1;
	res = (res < 0) ? (-res) : res;
	while (++i < l->pres && ++l->digit_len)
		write(1, "0", 1);
	(res == 0 && l->pres == 0 && l->pres_exist != 0) ? 1 : (ft_put(res, l, x));
	if (l->flag == '-')
		while (l->width-- && ++l->digit_len)
			write(1, " ", 1);
	printed = l->digit_len;
	return (printed);
}
