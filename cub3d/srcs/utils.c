/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:42:40 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:44:11 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		file_format(char *s, char *format)
{
	int i;
	int j;

	i = ft_strlen(s) - 1;
	j = ft_strlen(format) - 1;
	if (j >= i)
		return (0);
	while (j > 0)
	{
		if (s[i] != format[j])
			return (0);
		j--;
		i--;
	}
	return (1);
}

int		ft_isspace(char *line, int *i)
{
	while (line[*i] == '\t' || line[*i] == '\n' || line[*i] == '\v'
		|| line[*i] == '\r' || line[*i] == '\f' || line[*i] == ' ')
		(*i)++;
	return (1);
}

void	ft_errormessage(int i, t_all *all)
{
	(i == -1) ? write(2, "Error\nCan't allocate memory"
			"(malloc error)\n", 43) : 1;
	(i == -2) ? write(2, "Error\nInvalid map\n", 18) : 1;
	(i == -3) ? write(2, "Error\nMap should be rectangle\n", 30) : 1;
	(i == -4) ? write(2, "Error\nInvalid resolution\n", 25) : 1;
	(i == -5) ? write(2, "Error\nInvalid image(textures)\n", 30) : 1;
	(i == -6) ? write(2, "Error\nInvalid colour\n", 21) : 1;
	(i == -7) ? write(2, "Error\nExtra line/symbols in file"
			"or there is no player spawn spot\n", 66) : 1;
	(i == -8) ? write(2, "Error\nOne or few parameters"
			"is missing or invalid for some reason\n", 66) : 1;
	(i == -9) ? write(2, "Error\nCan not create"
			"or open screenshot file\n", 45) : 1;
	(i == -10) ? write(2, "Error\nCan't open file.\n", 23) : 1;
	close_prog(all);
}

void	close_prog(t_all *all)
{
	if (all->map.table != NULL)
		ft_free_map(all->map.table);
	if (all != NULL)
		free(all);
	exit(1);
}

int		ft_stringlen(char *line)
{
	int i;

	i = 0;
	while (*line)
	{
		if (*line == '0' || *line == '1' || *line == OK
			|| *line == OK + 1 || *line == '2'
			|| *line == 'N' || *line == 'S' || *line == 'W'
			|| *line == 'E' || *line == ' ')
			i++;
		line++;
	}
	return (i);
}
