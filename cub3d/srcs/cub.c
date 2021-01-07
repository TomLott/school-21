/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:49:25 by itollett          #+#    #+#             */
/*   Updated: 2021/01/06 13:53:51 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_work(char *arg, int i, t_all *all)
{
	all->win.mlx_ptr = mlx_init();
	(void)i;
	if (ft_parse(arg, all) < 0)
		ft_errormessage(all->err.x, all);
	if (all->counter != 8 || !all->tex.addr || !all->tex_e.addr
	|| !all->tex_n.addr || !all->tex_s.addr
	|| !all->tex_w.addr || !all->win.x
	|| !all->win.y || !all->tex.f || !all->tex.c)
		ft_errormessage(-8, all);
	ft_begining_all(all, i);
	return (0);
}

void	ft_start(char *arg, int i)
{
	t_all	*all;
	t_win	win;
	t_err	err;
	t_tex	tex;
	t_img	img;

	if (!(all = (t_all *)malloc(sizeof(t_all))))
		ft_errormessage(-1, all);
	all->save = (i == 1) ? 1 : 0;
	all->flag = 0;
	win.mlx_ptr = NULL;
	win.win = NULL;
	img.img = NULL;
	img.addr = NULL;
	err.n = 0;
	err.x = 0;
	win.x = 0;
	win.y = 0;
	tex.c = 0;
	tex.f = 0;
	ft_work(arg, i, all);
}

int		main(int argc, char **argv)
{
	if (argc == 3 && file_format(argv[1], ".cub")
	&& ft_strcmp(argv[2], "--save"))
		ft_start(argv[1], 1);
	else if (argc == 2 && file_format(argv[1], ".cub"))
		ft_start(argv[1], 0);
	else
		write(2, "Error: Invalid arguments\n", 26);
}
