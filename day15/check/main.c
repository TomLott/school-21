/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacqual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 22:05:11 by mjacqual          #+#    #+#             */
/*   Updated: 2020/08/06 18:05:01 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdio.h>
t_list		*ft_create_elem(void *data);
void		ft_list_push_front(t_list **begin_list, void *data);
int			ft_list_size(t_list *begin_list);
t_list		*ft_list_last(t_list *begin_list);
void		ft_list_push_back(t_list **begin_list, void *data);
t_list		*ft_list_push_strs(int size, char **strs);
void		ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list		*ft_list_at(t_list *begin_lst, unsigned int nbr);
void		ft_list_reverse(t_list **begin_list);
void		ft_list_foreach(t_list *begin_list, void (*f)(void *));
void		ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
*data_ref, int (*cmp)(void *, void*));
t_list		*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, void *));
void		ft_list_remove_if(t_list **begin_list, void *data_ref, int
(*cmp)(void *, void *), void (*free_fct)(void *));
void		ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void		ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *));
int		main(void)
{
	t_list	*head;
	int		n = 5;
	int		m = 6;
	int		k = 7;
	int		d = 8;
	int		f = 9;
	int		p = -384;
	int		r = 34;
	int		*c;

	head = ft_create_elem(&n);
	ft_list_push_front(&head, &m);
	ft_list_push_front(&head, &k);
	ft_list_push_front(&head, &d);
	printf("len %d\n", ft_list_size(head));
	printf("last el %d\n", *((int *)ft_list_last(head)->data));
	ft_list_push_back(&head, &f);
	ft_list_push_back(&head, &p);
	ft_list_push_front(&head, &r);
	ft_list_push_back(&head, &r);
	while (head)
	{
		c = head->data;
		printf("%d ", *c);
		head = head->next;
	}
	printf("\n");
	char *strs[] = {"wow", "wew", "waw", "wiw", "wte", "waaaw"};
	head = ft_list_push_strs(6, strs);
	while (head)
	{
		printf("%s\n", ((char *)head->data));
		head = head->next;
	}
	return (0);
}
