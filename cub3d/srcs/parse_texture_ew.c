/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_ew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:40:51 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:40:54 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_xmp_check_w(t_all *all, char *filename, t_tex_w *n)
{
	int fd;

	fd = 0;
	if (!file_format(filename, ".xpm"))
		return (-1);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	n->img = mlx_xpm_file_to_image(all->win.mlx_ptr, filename, &n->x, &n->y);
	if (!n->img)
		return (-1);
	n->addr = (unsigned int *)mlx_get_data_addr(n->img,
		&n->bits_per_pixel, &n->line_length, &n->endian);
	return (0);
}

int		ft_texture_w(t_all *all, char *line, int *i, t_tex_w *n)
{
	int		k;
	char	*filename;

	(*i) = (*i) + 2;
	ft_isspace(line, i);
	k = (*i);
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(filename = (char *)malloc(sizeof(char) * (*i - k + 1))))
		return (-1);
	*i = k;
	k = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		filename[k++] = line[(*i)++];
	filename[k] = '\0';
	k = ft_xmp_check_w(all, filename, n);
	free(filename);
	all->counter++;
	return (k == -1 ? -5 : 0);
}

int		ft_xmp_check_e(t_all *all, char *filename, t_tex_e *n)
{
	int fd;

	fd = 0;
	if (!file_format(filename, ".xpm"))
		return (-1);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	close(fd);
	n->img = mlx_xpm_file_to_image(all->win.mlx_ptr, filename, &n->x, &n->y);
	if (!n->img)
		return (-1);
	n->addr = (unsigned int *)mlx_get_data_addr(n->img,
		&n->bits_per_pixel, &n->line_length, &n->endian);
	return (0);
}

int		ft_texture_e(t_all *all, char *line, int *i, t_tex_e *n)
{
	int		k;
	char	*filename;

	(*i) = (*i) + 2;
	ft_isspace(line, i);
	k = (*i);
	while (line[*i] != ' ' && line[*i] != '\0')
		(*i)++;
	if (!(filename = (char *)malloc(sizeof(char) * (*i - k + 1))))
		return (-1);
	*i = k;
	k = 0;
	while (line[*i] != ' ' && line[*i] != '\0')
		filename[k++] = line[(*i)++];
	filename[k] = '\0';
	k = ft_xmp_check_e(all, filename, n);
	free(filename);
	all->counter++;
	return (k == -1 ? -5 : 0);
}
