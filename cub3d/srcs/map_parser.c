/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:40:21 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:47:30 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		zero_check(char **table, int i, int j)
{
	if (i <= 0 || j <= 0)
		return (0);
	if (j + 2 > (int)ft_strlen(table[i - 1]) || j + 2 >
		(int)ft_strlen(table[i + 1]))
		return (0);
	if (!(table[i - 1][j] == '0' || table[i - 1][j] == '2'
		|| table[i - 1][j] == '1' || table[i - 1][j] == OK
		|| table[i - 1][j] == OK + 1 || table[i - 1][j] == 'W'
		|| table[i - 1][j] == 'S' || table[i - 1][j] == 'N'
		|| table[i - 1][j] == 'E'))
		return (0);
	return (1);
}

int		map_ok(int i, int j, t_all *a)
{
	if (a->map.table[i][j] != '1' && a->map.table[i][j] != OK
		&& a->map.table[i][j] != OK + 1)
	{
		if (zero_check(a->map.table, i, j) == 0)
			return (0);
		if (a->map.table[i][j] == '0')
			a->map.table[i][j] = OK;
		if (a->map.table[i][j] == '2')
			a->map.table[i][j] = OK + 1;
		if (!map_ok(i - 1, j, a) || !map_ok(i + 1, j, a)
		|| !map_ok(i, j - 1, a) || !map_ok(i, j + 1, a))
			return (0);
	}
	return (1);
}

int		ft_check_map(t_all *all)
{
	int i;
	int j;

	i = 0;
	while (all->map.table[i])
	{
		j = 0;
		while (all->map.table[i][j])
		{
			if (all->map.table[i][j] == OK + 1)
				all->tex.sprite++;
			if (all->map.table[i][j] == '0')
			{
				if (!map_ok(i, j, all))
					return (-2);
			}
			j++;
		}
		i++;
	}
	all->map.y = i;
	return (0);
}

void	ft_mapping(t_all *all, t_list **head)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *head;
	if (!(all->map.table = (char **)malloc(sizeof(char *) * (all->map.counter + 1))))
		ft_errormessage(-2, all);
	while ((i++ < all->map.line_num) && temp)
		temp = temp->next;
	i = 0;
	while (temp)
	{
		all->map.table[i++] = ft_strdup(temp->content);
		free(temp->content);
		temp = temp->next;
	}
	all->map.table[i] = NULL;
	ft_checking_each(all->map.table, all);
}

void	ft_purgatorium(t_all *all, t_list **head)
{
	t_list	*temp;
	char	*cont;

	temp = *head;
	all->map.counter = 0;
	all->map.line_num = 0;
	while (temp)
	{
		cont = temp->content;
		if ((cont[0] != '1' && cont[0] != '0'
			&& cont[0] != ' ') && ++all->map.line_num)
			line_parse(cont, all);
		else
		{
			while (temp)
			{
				temp = temp->next;
				all->map.counter++;
			}
			break ;
		}
		temp = temp->next;
	}
	ft_mapping(all, head);
}
