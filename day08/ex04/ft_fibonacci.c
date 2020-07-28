/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:56:07 by itollett          #+#    #+#             */
/*   Updated: 2020/07/28 14:56:51 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int fim;

	fim = 0;
	if (index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	else
	{
		return (fim = ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
}
