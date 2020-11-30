/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:00:01 by itollett          #+#    #+#             */
/*   Updated: 2020/11/30 18:11:09 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_restart(t_list *options)
{
	options->flag = 0;
	options->width = 0;
	options->pres = 0;
	options->flag_len = 0;
	options->width_len = 0;
	options->pres_len = 0;
	options->pres_exist = 0;
	options->minus = 0;
	options->digit_len = 0;
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

void	ft_choise(const char *s, int i, va_list factor, t_list *temp)
{
	int		len;

	len = 0;
	i++;
	ft_restart(temp);
	temp->flag = ft_flags(s + i, temp);
	i += temp->flag_len;
	temp->width = ft_width((s + i), factor, temp);
	i += temp->width_len;
	if (s[i] == '.' && ft_check_pres(s[i + 1], temp) && ++i)
		temp->pres = ft_pres((s + i), factor, temp);
	i = (temp->pres_exist == -1) ? ++i : i;
	i = (s[i - 1] == '*') ? i : i + ft_strlen_int(temp->pres);
	temp->len = ft_len(temp);
}

int		ft_work(va_list factor, const char *s, t_list *opt)
{
	int		i;
	int		printed;
	int		temp;

	i = 0;
	printed = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_choise(s, i, factor, opt);
			i += opt->len + 1;
			if ((temp = ft_putchar_arg((s + i), factor, opt)) == -1)
				return (0);
			printed += temp;
		}
		else
		{
			write(1, &s[i], 1);
			printed++;
		}
		i++;
	}
	return (printed);
}

int		ft_printf(const char *s, ...)
{
	va_list factor;
	int		counter;
	t_list	*opt;

	va_start(factor, s);
	if (!(opt = (t_list *)malloc(sizeof(t_list))))
		return (-1);
	counter = ft_work(factor, s, opt);
	va_end(factor);
	free(opt);
	return (counter);
}
