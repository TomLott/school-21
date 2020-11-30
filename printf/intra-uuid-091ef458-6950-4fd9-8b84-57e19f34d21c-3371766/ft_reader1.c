/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 21:01:37 by itollett          #+#    #+#             */
/*   Updated: 2020/11/30 19:00:00 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putchar_arg(const char *s, va_list factor, t_list *opt)
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
	else if (*s == '%' && s++)
		printed = ft_print_percent(opt);
	else
		printed = -1;
	return (printed);
}

static int	ft_print_width(t_list *l, int s_len, char *s)
{
	int printed;

	printed = 0;
	if (l->flag != '-')
		while ((0 < l->width--) && ++printed)
			write(1, " ", 1);
	if (l->pres_exist >= 0)
	{
		write(1, s, s_len);
		printed += s_len;
	}
	if (l->flag == '-')
		while (0 < l->width-- && ++printed)
			write(1, " ", 1);
	return (printed);
}

int			ft_print_str(t_list *l, va_list factor)
{
	int		i;
	char	*str;
	int		s_len;

	i = 0;
	s_len = 0;
	str = va_arg(factor, char *);
	if (str == NULL)
		str = "(null)";
	if ((l->pres_exist <= 0 || (l->pres < 0 && l->pres_exist != 0)
				|| l->pres >= (int)ft_strlen(str)))
	{
		l->pres = 0;
		s_len = ft_strlen(str);
	}
	else
		s_len = l->pres;
	if (l->width && l->pres_exist == -1)
		l->width = l->width;
	else if (l->width && (l->width > s_len))
		l->width = l->width - s_len;
	else
		l->width = 0;
	return (ft_print_width(l, s_len, str));
}
