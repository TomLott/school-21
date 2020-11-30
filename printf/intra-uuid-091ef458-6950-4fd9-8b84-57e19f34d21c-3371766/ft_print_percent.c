/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:49:03 by itollett          #+#    #+#             */
/*   Updated: 2020/11/29 20:49:39 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_list *l)
{
	int len;
	int printed;

	printed = 0;
	len = (l->pres == 0 && l->pres_exist != 0) ? 0 : 1;
	if (l->pres > len)
		len = l->pres;
	if (l->width && l->flag == 0)
		while ((l->width--) - len && ++printed)
			write(1, " ", 1);
	if (l->width && l->flag == '0')
		while ((l->width--) - len && ++printed)
			write(1, "0", 1);
	if (len > 0)
	{
		write(1, "%", 1);
		printed++;
	}
	if (l->width && l->flag == '-')
		while ((l->width--) - 1 && ++printed)
			write(1, " ", 1);
	return (printed);
}
