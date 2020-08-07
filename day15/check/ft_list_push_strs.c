/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:47:45 by itollett          #+#    #+#             */
/*   Updated: 2020/08/06 21:12:10 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

void		ft_push(t_list **begin, char *str)
{
	t_list *list;

	list = ft_create_elem(str);
	if (*begin == 0)
		*begin = list;
	else
	{
		list->next = *begin;
		*begin = list;
	}
}

t_list		*ft_list_push_strs(int size, char **strs)
{
	t_list		*list;
	int			i;

	i = 0;
	list = 0;
	while (i < size)
	{
		ft_push(&list, strs[i]);
		i++;
	}
	return (list);
}
