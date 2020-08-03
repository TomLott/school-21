/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 21:51:21 by itollett          #+#    #+#             */
/*   Updated: 2020/08/01 22:03:26 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int					ft_len(char *av)
{
	int		i;

	i = 0;
	while (*(av + i) != '\0')
		i++;
	return (i);
}

char				*ft_copy(char *av)
{
	int		j;
	int		len;
	char	*copy;

	j = 0;
	len = ft_len(av);
	copy = malloc(sizeof(char**) * len);
	while (j < len)
	{
		copy[j] = av[j];
		j++;
	}
	copy[j++] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str *to;

	i = 0;
	to = malloc(sizeof(struct s_stock_str) * (ac + 1));
	while (i < ac)
	{
		to[i].size = ft_len(av[i]);
		to[i].str = av[i];
		to[i].copy = ft_copy(av[i]);
		i++;
	}
	to[i].size = 0;
	to[i].str = "";
	to[i].copy = "";
	return (to);
}
