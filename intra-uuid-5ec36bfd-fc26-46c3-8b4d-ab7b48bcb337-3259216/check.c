/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:56:28 by acaryn            #+#    #+#             */
/*   Updated: 2020/08/12 09:56:29 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		error(void)
{
	char *error;

	error = "map error\n";
	write(1, error, 10);
	return (0);
}

int		ft_final_check(char *buff)
{
	int	i;

	i = -1;
	while (buff[++i] != '\0')
		if (buff[i] != g_characters[1] &&
			buff[i] != g_characters[2] && buff[i] != '\n')
			return (0);
	return (1);
}

int		ft_atoi(char *buff)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	minus = 0;
	res = 0;
	while (buff[i] == ' ' || buff[i] == '\v' || buff[i] == '\t'
			|| buff[i] == '\f' || buff[i] == '\n' || buff[i] == '\r')
		i++;
	if (buff[i] == '+')
		i++;
	if (buff[i] == '-')
	{
		minus = 1;
		i++;
	}
	while (buff[i] >= '0' && buff[i] <= '9')
	{
		res = res * 10 + buff[i] - '0';
		i++;
	}
	if (minus == 1)
		res = -res;
	return (res);
}

int		ft_charact_check(char *row)
{
	int	i;

	i = -1;
	while (row[++i])
	{
		if (row[0] == '0' || !(row[0] >= '1' && row[0] <= '9'))
			return (0);
		if (!(row[i] >= '0' && row[i] <= '9'))
			return (0);
	}
	if (g_characters[0] == g_characters[1]
		|| g_characters[1] == g_characters[2]
			|| g_characters[0] == g_characters[2])
		return (0);
	if ((g_characters[0] >= 0 && g_characters[0] < 32)
		|| (g_characters[1] >= 0 && g_characters[1] < 32)
			|| (g_characters[2] >= 0 && g_characters[2] < 32))
		return (0);
	return (1);
}

int		ft_valid(char *temp)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	len = 0;
	if (temp[0] == '\0' || temp[0] == '\n')
		return (0);
	while (temp[len + i] != '\0')
	{
		while (temp[len + i] != '\n')
			i++;
		if (max == 0)
			max = i;
		else if (i != max)
			return (0);
		len = len + i + 1;
		i = 0;
	}
	return (1);
}
