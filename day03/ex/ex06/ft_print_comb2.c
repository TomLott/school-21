/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 11:53:50 by itollett          #+#    #+#             */
/*   Updated: 2020/07/23 11:59:30 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_two_numbers(int a, int b)
{
	char x;
	char y;
	char w;
	char z;

	x = a / 10 + '0';
	y = a % 10 + '0';
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, " ", 1);
	z = b / 10 + '0';
	w = b % 10 + '0';
	write(1, &z, 1);
	write(1, &w, 1);
	if (a != 98)
	{
		write(1, "," " ", 2);
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_two_numbers(a, b);
			b++;
		}
		a++;
	}
}
