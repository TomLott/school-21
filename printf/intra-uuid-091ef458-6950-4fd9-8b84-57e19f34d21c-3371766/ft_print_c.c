/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:34:44 by itollett          #+#    #+#             */
/*   Updated: 2020/11/29 20:36:15 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_width(t_list *l, int printed, char c)
{
	int i;

	i = 0;
	if (l->flag != '-' && l->width)
	{
		while (i < l->width)
		{
			write(1, " ", 1);
			i++;
			printed++;
		}
	}
	write(1, &c, 1);
	printed++;
	i = 0;
	if (l->flag == '-' && l->width)
	{
		while (i < l->width)
		{
			write(1, " ", 1);
			i++;
			printed++;
		}
	}
	return (printed);
}

int			ft_print_c(t_list *list, va_list factor)
{
	int i;
	int c;
	int printed;

	printed = 0;
	i = 0;
	c = va_arg(factor, int);
	list->width--;
	return (ft_print_width(list, printed, c));
}
