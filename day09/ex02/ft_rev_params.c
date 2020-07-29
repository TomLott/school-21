/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:25:38 by itollett          #+#    #+#             */
/*   Updated: 2020/07/29 13:26:21 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int j;

	(void)argv;
	(void)argc;
	i = 0;
	j = argc;
	while (j > 1)
	{
		while (argv[j - 1][i] != '\0')
		{
			i++;
		}
		write(1, argv[j - 1], i);
		j--;
		i = 0;
		write(1, "\n", 1);
	}
}
