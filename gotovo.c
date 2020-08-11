/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:40:13 by acaryn            #+#    #+#             */
/*   Updated: 2020/08/04 16:14:55 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#define BUF 30000
#define STDIN 0
#define STDOUT 1

void	ft_putstr(int p, char *str)
{
	int		i;
	char	c;

	i = 0;
	while (*(str + i))
	{
		c = *(str + i);
		write(p, &c, 1);
		i++;
	}
}

int		ft_cmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) && *(s2 + i))
		i++;
	return (*(s1 + i) - *(s2 + i));
}

int		display_file(char *argv)
{
	int		fd;
	int		rd;
	char	str[BUF];

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	while ((rd = read(fd, str, BUF)) > 0)
		write(1, &str, rd);
	if (rd < 0)
		return (0);
	close(fd);
	return (1);
}

void	error_check(char *a, char *b)
{
	ft_putstr(1, basename(a));
	ft_putstr(1, ": ");
	ft_putstr(1, b);
	ft_putstr(1, ": ");
	ft_putstr(2, strerror(errno));
	ft_putstr(1, "\n");
}

int		main(int argc, char **argv)
{
	int		i;
	char	str[BUF];
	int		n;

	i = 1;
	if (argc < 2)
		while ((n = read(STDIN, str, BUF)) > 0)
			write(STDOUT, str, n);
	while (i < argc)
	{
		if (!ft_cmp("--", argv[i]) && (i == 1) && (argc > 2))
		{
			i++;
			continue ;
		}
		else if (!ft_cmp("-", argv[i]) || ((i == 1) && !ft_cmp("--", argv[i])))
		{
			while ((n = read(STDIN, str, BUF)) > 0)
				write(STDOUT, str, n);
		}
		else if (!display_file(*(argv + i)))
			error_check(*(argv), *(argv + i));
		i++;
	}
	return (0);
}
