/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:47:39 by itollett          #+#    #+#             */
/*   Updated: 2020/07/30 20:35:51 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *range;
	int i;
	int j;

	i = 0;
	j = 0;
	i = max - min;
	range = (int*)malloc(sizeof(range) * i);
	if (min >= max)
	{
		return (0);
	}
	while (j < i)
	{
		range[j] = min;
		min++;
		j++;
	}
	return (range);
}
