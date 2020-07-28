/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 09:23:45 by itollett          #+#    #+#             */
/*   Updated: 2020/07/26 11:47:06 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;

	i = 0;
	while (*(dest + i) != '\0')
	{
		i++;
	}
	while (nb != 0 && *src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
		nb--;
	}
	return (dest);
}
