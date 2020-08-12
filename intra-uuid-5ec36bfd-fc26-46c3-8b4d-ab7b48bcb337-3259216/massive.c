/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   massive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:59:55 by acaryn            #+#    #+#             */
/*   Updated: 2020/08/12 09:59:56 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		*ft_strdupint(char *row, int column, int *mas)
{
	int i;

	i = -1;
	if ((mas = (int*)malloc(sizeof(int) * column)) != NULL)
	{
		while (++i < column)
			if (row[i] == g_characters[1])
				mas[i] = 0;
			else if (row[i] == g_characters[2])
				mas[i] = 1;
	}
	return (mas);
}

int		**ft_translate(int row, int column, char **massive)
{
	int	i;
	int	**massiveint;

	i = -1;
	if ((massiveint = (int**)malloc(sizeof(int*) * row)) != NULL)
		while (++i < row)
			massiveint[i] = ft_strdupint(massive[i], column, massiveint[i]);
	return (massiveint);
}

void	ft_defining(char *buff, int j)
{
	int		i;
	char	*characters;

	i = -1;
	if ((characters = (char*)malloc(sizeof(char) * 3)) != NULL)
	{
		while (++i < 3)
			characters[i] = buff[(j--) - 1];
		buff[j] = '\0';
	}
	if ((g_characters = (char*)malloc(sizeof(char) * 3)) != NULL)
	{
		i = -1;
		while (++i < 3)
			g_characters[i] = characters[i];
	}
}

char	*ft_strdup(char *src, int k)
{
	char	*tab;
	int		len;

	len = 0;
	while (src[len + k] != '\n')
		len++;
	if ((tab = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	len = 0;
	while (src[len + k] != '\n')
	{
		tab[len] = src[len + k];
		len++;
	}
	tab[len] = '\0';
	return (tab);
}

int		ft_massive(int att, char *buff, int j, int k)
{
	int		len;
	int		shit;
	int		**t2;
	char	**massive;

	shit = 1;
	j = -1;
	k = 0;
	len = ft_strlenspecial(buff);
	if ((massive = (char**)malloc(sizeof(char*) * att)) == NULL)
		return (0);
	while (++j < att)
	{
		massive[j] = ft_strdup(buff, k);
		k = len / att * shit;
		shit++;
	}
	if (ft_final_check(buff) == 0)
		return (0);
	j = len / att;
	t2 = ft_translate(att, j - 1, massive);
	k = -1;
	ft_free(buff, massive, att);
	find(att, j - 1, k, t2);
	return (1);
}
