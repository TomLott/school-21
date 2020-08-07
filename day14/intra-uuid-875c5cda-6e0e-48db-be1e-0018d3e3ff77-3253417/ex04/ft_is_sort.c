/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:56:17 by itollett          #+#    #+#             */
/*   Updated: 2020/08/05 20:17:01 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int j;
	int sum;

	i = 1;
	j = 1;
	sum = 0;
	if (length == 0 || length == 1)
		return (1);
	while (i <= (length) && j <= (length) && sum <= length)
	{
		if (f(tab[i - 1], tab[i]) >= 0)
			i++;
		if (f(tab[j], tab[j - 1]) >= 0)
			j++;
		sum++;
		if (j == (length) || i == (length))
			return (1);
	}
	return (0);
}
