/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:33:53 by itollett          #+#    #+#             */
/*   Updated: 2020/11/30 18:08:47 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr_fd(char *s, int fd, t_list *l)
{
	if (s)
	{
		l->digit_len = ft_strlen(s);
		write(fd, s, ft_strlen(s));
	}
}

static int	ft_length(int c, t_list *l)
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

static void	ft_putnbr_fd(int n, int fd, t_list *l)
{
	int temp;

	if (n == -2147483648)
	{
		l->digit_len = 10;
		ft_putstr_fd("2147483648", fd, l);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, l);
		ft_putnbr_fd(-n, fd, l);
	}
	else if (n < 10)
		ft_putchar_fd(n + 48, fd, l);
	else
	{
		temp = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd, l);
		ft_putchar_fd(temp, fd, l);
	}
}

static void	ft_print_width(t_list *l, int len, int res)
{
	if (l->flag == '0' && l->pres < 0)
	{
		l->pres = l->width;
		if (res < 0 && l->pres != 0)
			l->pres--;
		l->width = 0;
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
	if (l->width > len + l->pres && l->pres >= 0)
		l->width = l->width - len - l->pres;
	else if (l->width <= len + l->pres)
		l->width = 0;
	if (l->pres == 0 && l->pres_exist != 0 && res == 0 && l->width != 0)
		l->width++;
}

int			ft_print_int(t_list *l, va_list factor)
{
	int i;
	int res;
	int printed;
	int len;

	i = -1;
	printed = 0;
	res = va_arg(factor, int);
	len = ft_length(res, l);
	ft_print_width(l, len, res);
	if (l->flag != '-')
		while (l->width-- > 0 && ++printed)
			write(1, " ", 1);
	(res < 0) ? write(1, "-", 1) && ++printed : 1;
	res = (res < 0) ? (-res) : res;
	while (++i < l->pres && ++printed)
		write(1, "0", 1);
	(res == 0 && l->pres == 0 && l->pres_exist != 0)
		? 1 : (ft_putnbr_fd(res, 1, l));
	if (l->flag == '-')
		while (l->width-- && ++printed)
			write(1, " ", 1);
	printed += l->digit_len;
	return (printed);
}
