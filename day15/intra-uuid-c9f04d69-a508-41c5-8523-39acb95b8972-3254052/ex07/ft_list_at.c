/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:19:16 by itollett          #+#    #+#             */
/*   Updated: 2020/08/06 22:20:28 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	int			i;
	t_list		*list;

	i = 0;
	list = begin_list;
	while (i < nbr)
	{
		list = list->next;
		i++;
	}
	return (list);
}
