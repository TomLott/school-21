/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:17:56 by itollett          #+#    #+#             */
/*   Updated: 2020/08/04 18:09:07 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

char	ft_putstr(char *str, char *argv);

int		ft_write(char *argv, int argc)
{
	int		i;
	char	echo[30000];
	int		len2;

	i = 0;
	len2 = 0;
	if (argc == 1 || *argv == '-')
	{
		while ((len2 = read(1, echo, 30000)) > 0)
			write(1, echo, len2);
		if (argc == 1)
			return (0);
	}
	else
	{
		if (((i = open(argv, O_RDWR)) == -1)
			|| (len2 = read(1, argv, 30000)) < 0)
		{
			ft_putstr(strerror(errno), argv);
			return (0);
		}
	}
	return (0);
}
