/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:01:09 by itollett          #+#    #+#             */
/*   Updated: 2020/07/27 13:05:34 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_reverse(int nb)
{
	char x;

	if (nb != 0)
	{
		x = nb % 10 + '0';
		nb = nb / 10;
		ft_reverse(nb);
		write(1, &x, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb != -2147483648 && nb != 2147483647 && nb != 0)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		ft_reverse(nb);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-2147483648", 11);
		}
		else if (nb > 0)
		{
			write(1, "2147483647", 10);
		}
		else
		{
			write(1, "0", 1);
		}
	}
}
