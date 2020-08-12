/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:47:34 by acaryn            #+#    #+#             */
/*   Updated: 2020/08/12 09:47:37 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_free(char *str1, char **str2, int att)
{
	int i;

	i = -1;
	free(str1);
	if (att > 1)
		while (++i < att)
			free(str2[i]);
	free(str2);
}

char	*create_file(void)
{
	char	str;
	int		h;
	char	*file;

	file = "our.txt";
	if ((h = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0600)) == -1)
		return (NULL);
	while (read(0, &str, 1))
		write(h, &str, 1);
	close(h);
	return (file);
}

int		print_map(char *file)
{
	char	*attributes;
	int		attrib;

	if ((attributes = ft_read(file)) == NULL)
		return (0);
	if (ft_charact_check(attributes) == 0)
		return (0);
	else
	{
		attrib = ft_atoi(attributes);
		if (ft_create_massive(file, attrib) == 0)
			return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*file;

	i = 0;
	if (argc == 1)
	{
		file = create_file();
		write(1, "\n", 1);
		if (print_map(file) == 0)
			error();
	}
	else
		while (++i < argc)
		{
			if (print_map(argv[i]) == 0)
				error();
			if (i != (argc - 1))
				write(1, "\n", 1);
		}
	return (0);
}
