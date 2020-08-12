/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:53:59 by acaryn            #+#    #+#             */
/*   Updated: 2020/08/12 09:54:00 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_print(int **temp, int row, int column)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < row)
	{
		while (++j < column)
		{
			if (temp[i][j] == 0)
				write(1, &g_characters[1], 1);
			else if (temp[i][j] == -1)
				write(1, &g_characters[0], 1);
			else
				write(1, &g_characters[2], 1);
		}
		j = -1;
		write(1, "\n", 1);
	}
	i = -1;
	if (row > 1)
		while (++i < row)
			free(temp[i]);
	free(temp);
	free(g_characters);
}

int		**ft_change(int **temp, int maxi, int maxj, int maxs)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < maxs)
	{
		while (++j < maxs)
		{
			temp[maxi][maxj] = -1;
			maxj--;
		}
		j = -1;
		maxj += maxs;
		maxi--;
	}
	return (temp);
}

int		m(int a, int b, int c)
{
	if (a > b)
		a = b;
	else if (a > c)
		a = c;
	return (a);
}

int		max(int **t, int row, int column, int i)
{
	int	maxs;
	int	maxi;
	int	maxj;
	int	j;

	if (t == NULL)
		return (error());
	maxs = t[0][0];
	maxi = 0;
	maxj = 0;
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < column)
			if (maxs < t[i][j])
			{
				maxs = t[i][j];
				maxi = i;
				maxj = j;
			}
	}
	ft_change(t, maxi, maxj, maxs);
	ft_print(t, row, column);
	return (1);
}

void	find(int row, int column, int i, int **t2)
{
	int	j;
	int	**t;

	if ((t = (int**)malloc(sizeof(int*) * row)) != NULL)
	{
		while (++i < row)
		{
			j = -1;
			if ((t[i] = (int*)malloc(sizeof(int) * column)) != NULL)
				while (++j < column)
					t[i][j] = t2[i][j];
		}
		i = 0;
		while (++i < row)
		{
			j = 0;
			while (++j < column)
				if (t2[i][j] == 1)
					t[i][j] = m(t[i][j - 1], t[i - 1][j], t[i - 1][j - 1]) + 1;
				else
					t[i][j] = 0;
		}
		free(t2);
	}
	max(t, row, column, i);
}
