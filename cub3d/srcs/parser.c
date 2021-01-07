/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:41:13 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:47:04 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_resol(t_all *all, char *line, int *i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (line[*i] == 'R')
		(*i)++;
	ft_isspace(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
		x = x * 10 + (line[(*i)++] - '0');
	ft_isspace(line, i);
	while (line[*i] >= '0' && line[*i] <= '9')
		y = y * 10 + (line[(*i)++] - '0');
	mlx_get_screen_size(all->win.mlx_ptr, &all->win.x, &all->win.y);
	if (!(x > all->win.x))
		all->win.x = x;
	if (!(y > all->win.y))
		all->win.y = y;
	if (!all->win.y || !all->win.x)
		return (-4);
	all->counter++;
	return (0);
}

void		line_parse(char *line, t_all *all)
{
	int	i;

	i = 0;
	if (line[i] == 'R')
		all->err.x = ft_resol(all, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->err.x = ft_texture_s(all, line, &i, &all->tex_s);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		all->err.x = ft_texture_n(all, line, &i, &all->tex_n);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		all->err.x = ft_texture_w(all, line, &i, &all->tex_w);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		all->err.x = ft_texture_e(all, line, &i, &all->tex_e);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		all->err.x = ft_texture(all, line, &i, &all->tex);
	else if ((line[i] == 'C' || line[i] == 'F') && line[i + 1] == ' ')
		all->err.x = ft_colour(line, &i, all);
	else
		all->err.x = (line[0] == 0) ? 1 : -8;
	ft_isspace(line, &i);
	if (all->err.x == 0 && line[i])
		all->err.x = -7;
	free(line);
	if (all->err.x < 0)
		ft_errormessage(all->err.x, all);
}

void		ft_checking_each(char **table, t_all *all)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (table[i])
	{
		j = 0;
		while (table[i][j])
		{
			c = table[i][j];
			if (c != '0' && c != '2'
				&& c != 'W' && c != 'S' && c != 'N'
				&& c != 'E' && c != ' ' && c != '1')
				all->err.x = 2;
			j++;
		}
		i++;
	}
}

int			tc(t_all *a)
{
	int i;
	int j;

	i = 0;
	while (i < a->map.counter - 1)
	{
		if ((j = ft_stringlen(a->map.table[i])) < 5)
			return (-1);
		i++;
	}
	return (i < 5) ? -1 : 1;
}

int			ft_parse(char *arg, t_all *all)
{
	char		*line;
	int			fd;
	t_list		*head;
	t_list		*temp;

	head = NULL;
	all->counter = 0;
	((fd = open(arg, O_RDONLY)) <= 0) ? ft_errormessage(-10, all) : 1;
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	close(fd);
	ft_purgatorium(all, &head);
	temp = head;
	while (temp->next)
	{
		head = temp->next;
		free(temp);
		temp = head;
	}
	free(head);
	if (all->err.x < 0 || tc(all) == -1 || ft_check_map(all) == -2)
		ft_errormessage(-2, all);
	all->err.x = ft_player_parser(all, fd);
	return (all->err.x);
}
