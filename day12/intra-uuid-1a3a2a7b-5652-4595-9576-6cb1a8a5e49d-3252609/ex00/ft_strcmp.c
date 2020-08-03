/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 19:20:27 by itollett          #+#    #+#             */
/*   Updated: 2020/07/25 19:20:54 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int x;

	while (*s1 != '\0' && *s2 != '\0')
	{
		if (!(*s1 == *s2))
		{
			x = *s1 - *s2;
			return (x);
		}
		else
		{
			s1++;
			s2++;
		}
	}
	if (*s1 == '\0')
	{
		x = *s1 - *s2;
	}
	if (*s2 == '\0')
	{
		x = *s1 - *s2;
	}
	return (x);
}
