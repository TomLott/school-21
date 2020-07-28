/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:48:56 by itollett          #+#    #+#             */
/*   Updated: 2020/07/22 21:55:31 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	func(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!(a == '7' && b == '8'))
	{
		write(1, ", ", 1);
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				func(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
