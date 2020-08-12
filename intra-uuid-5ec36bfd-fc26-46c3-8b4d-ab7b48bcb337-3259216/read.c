/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:02:23 by acaryn            #+#    #+#             */
/*   Updated: 2020/08/12 10:02:24 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_strlenspecial(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] >= 9 && buff[i] <= 126)
		i++;
	return (i);
}

char	*ft_read(char *argv)
{
	char	*buff;
	int		file;
	int		j;
	char	c;
	int		rd;

	j = 0;
	c = 0;
	file = 0;
	if ((buff = (char*)malloc(sizeof(char) * 14)) != NULL)
	{
		if ((file = open(argv, O_RDONLY)) == -1)
			return (NULL);
		while ((rd = read(file, &c, 1) > 0 && c != '\n') > 0)
			buff[j++] = c;
		if (rd < 0)
			return (NULL);
		buff[j] = '\0';
	}
	ft_defining(buff, j);
	close(file);
	return (buff);
}

char	*ft_read_file(char *argv)
{
	int		file;
	int		i;
	char	c;
	char	*temp;

	i = 0;
	if ((file = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while (read(file, &c, 1) > 0 && c != '\n')
		i = 0;
	while (read(file, &c, 1) > 0)
		i++;
	close(file);
	if ((temp = (char*)malloc(sizeof(char) * i + 1)) != NULL)
	{
		if ((file = open(argv, O_RDONLY)) == -1)
			return (NULL);
		while (read(file, &c, 1) > 0 && c != '\n')
			i = 0;
		while (read(file, &c, 1) > 0)
			temp[i++] = c;
		temp[i] = '\0';
	}
	close(file);
	return (temp);
}

int		ft_create_massive(char *argv, int att)
{
	int		file;
	char	*temp;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	if ((file = open(argv, O_RDONLY)) == -1)
		return (0);
	temp = ft_read_file(argv);
	while (temp[i++] != 0)
		if (temp[i] == '\n')
			counter++;
	if (counter != att || ft_valid(temp) == 0)
		return (0);
	if (ft_massive(att, temp, i, i) == 0)
		return (0);
	close(file);
	return (1);
}
