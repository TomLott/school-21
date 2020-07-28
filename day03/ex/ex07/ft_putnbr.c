/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:12:27 by itollett          #+#    #+#             */
/*   Updated: 2020/07/23 13:17:11 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_reverse(int nb)
{
	char out;

	if (nb % 10 > 0)
	{
		out = nb % 10 + '0';
		nb = nb / 10;
		ft_reverse(nb);
		write(1, &out, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	ft_reverse(nb);
}
