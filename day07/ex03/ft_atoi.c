/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:06:39 by itollett          #+#    #+#             */
/*   Updated: 2020/07/28 08:53:41 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_change(char *tr, int i)
{
	int num;
	int k;

	num = 0;
	k = 1;
	if (tr[0] == '0')
	{
		return (0);
	}
	while (i - 1 >= 0)
	{
		num = num + (tr[i - 1] - '0') * k;
		i--;
		k = k * 10;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int			x;
	char		tr[11];
	int			i;
	int			fnum;

	x = 0;
	i = 0;
	while (*str == 43 || *str == 45 || *str <= 32)
	{
		if (*str == 45)
		{
			x++;
		}
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		tr[i] = *str;
		str++;
		i++;
	}
	fnum = (ft_change(tr, i));
	if (x % 2 == 1)
		fnum = -fnum;
	return (fnum);
}
