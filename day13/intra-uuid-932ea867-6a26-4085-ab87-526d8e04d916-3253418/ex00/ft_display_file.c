/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:45:51 by itollett          #+#    #+#             */
/*   Updated: 2020/08/03 14:08:53 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		file;
	char	c;

	file = open(argv[1], O_RDONLY);
	if (argc == 1)
		write(1, "File name missing.", 19);
	else if (argc > 2)
		write(1, "Too many arguments.", 20);
	else if (file == -1)
		write(1, "Cannot read file.", 17);
	else
	{
		while (read(file, &c, 1))
		{
			write(1, &c, 1);
		}
	}
	write(1, "\n", 1);
	close(file);
	return (0);
}
