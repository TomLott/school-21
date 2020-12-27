#include "../includes/cub.h"

void ft_reverse_sp(t_sprite *sp, t_all *a)
{
	int i;
	int max;
	t_sprite temp;

	i = 0;
	max = a->tex.sprite;
	while (i < max - 1)
	{
		temp = sp[i];
		sp[i] = sp[i + 1];
		sp[i + 1] = temp;
		i++;
	}
}

void ft_sort_that_sht(t_sprite *sp, int num, t_all *a)
{
	int i;
	int j;
	int ord;
	t_sprite temp;

	i = 0;
	while (i < num - 1)
	{
		j = 0;
		while (j < num - i - 1)
		{
			if (sp[j].dist > sp[j + 1].dist)
			{
				temp = sp[j];
				sp[j] = sp[j + 1];
				sp[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	ft_reverse_sp(sp, a);
}

void ft_find_spr(t_all *a, t_sprite *sp)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < a->map.y)
	{
		j = 0;
		while(j < ft_strlen(a->map.table[i]))
		{
			if (a->map.table[i][j] == OK + 1)
			{
				sp[k].x = j;
				sp[k].y = i;
				k++;
			}
			j++;
		}
		i++;
	}
}

void ft_sprite(t_all *a, t_dist *d, t_cam *c)
{
	int i;
	int j;

	i = 0;
	a->sp = (t_sprite *)malloc(sizeof(t_sprite) * (a->tex.sprite + 1));
	ft_find_spr(a, a->sp);
	while (i < a->tex.sprite)
	{
		a->sp[i].ord = i;
		a->sp[i].dist = (a->cam.posX - 0.5 - a->sp[i].x) * (a->cam.posX - 0.5 - a->sp[i].x)
						  + (a->cam.posY - 0.5 - a->sp[i].y) * (a->cam.posY - 0.5 - a->sp[i].y);
		i++;
	}
	ft_sort_that_sht(a->sp, a->tex.sprite, a);
	ft_spr_cast(a->sp, a, &a->tex);
}