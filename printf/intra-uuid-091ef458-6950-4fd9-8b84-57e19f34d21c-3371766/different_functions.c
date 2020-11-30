/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:25:42 by itollett          #+#    #+#             */
/*   Updated: 2020/11/30 18:07:01 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_common_print(const char *s)
{
	if (*s == '%' && *(s + 1) == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
	{
		write(1, s, 1);
		return (0);
	}
}

int		ft_check(const char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	if (s == 'd' || s == 'x' || s == 's'
			|| s == 'X' || s == 'c' || s == 'i'
			|| s == 'p' || s == 'u')
		return (1);
	if (s == '.' || s == '*' || s == '-' || s == '%')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *string)
{
	char	*temp;
	size_t	i;

	temp = (char *)string;
	i = 0;
	while (temp[i] != '\0')
		i++;
	return (i);
}

int		ft_check_pres(const char s, t_list *list)
{
	if (s >= '0' && s <= '9')
		return (1);
	if (s == '*')
		return (1);
	else if (s == 'd' || s == 'x' || s == 's'
			|| s == 'X' || s == 'c' || s == 'i'
			|| s == 'p' || s == 'u')
	{
		list->pres_exist = -1;
		return (0);
	}
	list->pres_exist = 0;
	return (0);
}

void	ft_putchar_fd(char c, int fd, t_list *l)
{
	write(fd, &c, 1);
	l->digit_len++;
}
