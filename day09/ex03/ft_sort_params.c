/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:50:55 by itollett          #+#    #+#             */
/*   Updated: 2020/07/29 15:36:42 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_compare(char *s1, char *s2)
{
	int x;

	x = 0;
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (!(*s1 == *s2))
		{
			x = *s1 - *s2;
			return (x);
		}
		else
		{
			s1++;
			s2++;
		}
	}
	return (0);
}

void	ft_print(int argc, char **argv)
{
	int		f;
	int		len;

	len = 0;
	f = 1;
	while (f < argc)
	{
		while (argv[f][len] != '\0')
		{
			len++;
		}
		write(1, argv[f], len);
		write(1, "\n", 1);
		len = 0;
		f++;
	}
}

int		main(int argc, char **argv)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	(void)argc;
	j = argc - 1;
	(void)argv;
	while (i < j)
	{
		while (j > i)
		{
			if (ft_compare(argv[j - 1], argv[j]) > 0)
			{
				buf = argv[j];
				argv[j] = argv[j - 1];
				argv[j - 1] = buf;
			}
			j--;
		}
		i++;
		j = argc - 1;
	}
	ft_print(argc, argv);
}
