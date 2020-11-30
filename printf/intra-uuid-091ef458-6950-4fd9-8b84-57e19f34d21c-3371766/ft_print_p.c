/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:43:04 by itollett          #+#    #+#             */
/*   Updated: 2020/11/30 18:09:06 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length(size_t num, t_list *l)
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

static void	ft_put(size_t n, t_list *l, char x)
{
	int temp;

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
		if ((n % 16) < 10)
			temp = n % 16 + 48;
		else
			temp = (x == 'x') ? (n % 16 + 87) : (n % 16 + 55);
		ft_put(n / 16, l, x);
		ft_putchar_fd(temp, 1, l);
	}
}

static void	ft_print_width(t_list *l, int len, size_t res)
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
	else if ((l->pres <= len + l->minus && l->pres >= 0) || l->pres < 0)
		l->pres = 0;
	if (l->width > (len - l->minus + l->pres))
		l->width = l->width - l->pres - len;
	else if (l->width <= (len + l->pres))
		l->width = 0;
}

int			ft_print_p(t_list *l, va_list factor)
{
	int		printed;
	size_t	res;
	int		len;

	res = va_arg(factor, size_t);
	len = ft_length(res, l) + 2;
	ft_print_width(l, len, res);
	(!res && !l->pres && l->width && l->pres_exist) ? l->width++ : 1;
	while (l->flag != '-' && l->width-- > 0 && ++l->digit_len)
		write(1, " ", 1);
	if (!res && l->pres <= 0 && l->pres_exist == -1 && (l->digit_len += 2))
		write(1, "0x", 2);
	else
	{
		write(1, "0x", 2);
		l->digit_len += 2;
		while (l->pres-- > 0 && ++l->digit_len)
			write(1, "0", 1);
		ft_put(res, l, 'x');
	}
	while (l->flag == '-' && l->width-- > 0 && ++l->digit_len)
		write(1, " ", 1);
	printed = l->digit_len;
	return (printed);
}
