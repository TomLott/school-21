/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:12:44 by itollett          #+#    #+#             */
/*   Updated: 2020/07/30 20:54:35 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*tab;
	int		len;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	tab = malloc(sizeof(tab) * len);
	if (tab == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	len = 0;
	while (src[len] != '\0')
	{
		tab[len] = src[len];
		len++;
	}
	return (tab);
}
