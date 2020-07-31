/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:47:09 by itollett          #+#    #+#             */
/*   Updated: 2020/07/30 20:54:21 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
void	ft_check(int min, int max)
{
	if (min >= max)
	{
		return (0);
	}
}

void	ft_check2(int **range)
{
	if (range == NULL)
	{
		errno = ENOMEM;
		return (-1);
	}
}

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		j;
	int		*newr;

	j = 0;
	i = max - min;
	ft_check(min, max);
	ft_check2(range);
	range = malloc(sizeof(**range) * i);
	newr = malloc(sizeof(newr) * i);
	while (j < i)
	{
		newr[j] = min;
		min++;
		j++;
	}
	j = 0;
	while (j < i)
	{
		range[j] = &newr[j];
		j++;
	}
	return (j);
}
