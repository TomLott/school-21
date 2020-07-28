/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 11:54:21 by itollett          #+#    #+#             */
/*   Updated: 2020/07/28 11:54:49 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int res, int nb, int power)
{
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

int	ft_iterative_power(int nb, int power)
{
	int res;

	res = 1;
	if (nb == 0 && power == 0)
	{
		return (0);
	}
	if (power == 0 && nb < 0)
	{
		return (-1);
	}
	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	return (ft_power(res, nb, power));
}
