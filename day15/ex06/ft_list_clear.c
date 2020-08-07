/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:53:23 by itollett          #+#    #+#             */
/*   Updated: 2020/08/06 21:57:16 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fcr)(void *))
{
	t_list *list;

	while (begin_list)
	{
		list = begin_list;
		begin_list = begin_list->next;
		free_fct(list->data);
		free(list);
	}
}
