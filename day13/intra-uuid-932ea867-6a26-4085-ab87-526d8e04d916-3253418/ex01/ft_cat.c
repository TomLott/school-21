/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 15:17:54 by itollett          #+#    #+#             */
/*   Updated: 2020/08/04 18:07:55 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <libgen.h>
#include "ft.h"

char	ft_putstr(char *str, char *argv)
{
	int i;

	i = 0;
	write(1, "cat: ", 5);
	while (argv[i] != '\0')
		i++;
	write(1, argv, i);
	write(1, ": ", 2);
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != s2[i])
		i++;
	i = s1[i] - s2[i];
	return (i);
}

int		print(int len, int *file, char *c, int i)
{
	while (len != 0)
	{
		write(1, &c[0], len);
		len = read(file[i - 1], &c[0], 30000);
	}
	return (len);
}

int		ft_dir(int file, int argc)
{
	int i;

	i = 0;
	if (file <= 0 && argc == 2)
	{
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	int		file[1000];
	char	c[30000];
	int		len;

	i = 1;
	while (i < argc || argc == 1)
	{
		file[i - 1] = open(argv[i], O_RDWR);
		if (file[i - 1] != -1)
		{
			len = read(file[i - 1], &c[0], 30000);
			while (len != 0)
				len = print(len, file, c, i);
			i++;
		}
		if (file[i - 1] == -1)
		{
			ft_write(argv[i], argc);
			return (0);
		}
		close(file[i - 1]);
	}
	return (0);
}
