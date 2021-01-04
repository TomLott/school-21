#include "../includes/cub.h"

void ft_print_sprite(t_all *a, t_tex *t, int j, int i)
{
	unsigned int colour;
	char *dst;

	colour = *(unsigned int *)(t->addr + (t->tex_y) * t->y + t->tex_x);
	if((colour & 0x00FFFFFF) != 0)
	{
		dst = a->img.addr + (j * a->img.line_length + i * (a->img.bits_per_pixel / 8));
		*(unsigned int *) dst = colour;
	}

}

void ft_draw_sprite(t_all *a, t_sprite sp, t_tex *t, int move_scr)
{
	int d;
	int i;
	int j;


	i = t->start_x;
	while (i < t->end_x)
	{
		t->tex_x = (int) (256 * (i - (-(t->wid )/ 2 + t->sp_scr_x)) * t->x / t->wid) / 256;
		if (t->tr_y > 0 && i > 0 && i < a->win.x && t->tr_y < a->tex.sp_buf[i])
		{
			j = t->start_y;
			while (j < t->end_y)
			{
				d = ((j - move_scr)) * 256 - a->win.y * 128 + t->hig * 128;
				t->tex_y = ((d * t->y) / t->hig) / 256;
				ft_print_sprite(a, t, j, i);
				j++;
			}
		}
		i++;
	}
}

void ft_sprite_height(t_all *a, t_sprite sp, t_tex *t)
{
	int h;
	int move_scr;


	move_scr = (int)((MOVE_SCR + sp.dist) / t->tr_y);
	h = a->win.y;
	t->hig = abs((int)(h / t->tr_y));
	t->start_y = -t->hig / 2 + h / 2 + move_scr;
	t->start_y = (t->start_y < 0) ? 0 : t->start_y;
	t->end_y = t->hig / 2 + h / 2 + move_scr;
	t->end_y = (t->end_y >= h) ? h - 1 : t->end_y;
	t->wid = abs((int)(h / t->tr_y));
	t->start_x = -t->wid / 2 + t->sp_scr_x;
	t->start_x = (t->start_x < 0) ? 0 : t->start_x;
	t->end_x = t->wid / 2 + t->sp_scr_x;
	t->end_x = (t->end_x >= a->win.x) ? a->win.x - 1 : t->end_x;
	ft_draw_sprite(a, sp, t, move_scr);
}

void ft_spr_cast(t_sprite *sp, t_all *a, t_tex *t)
{
	int i;

	i = 0;
	while (i < a->tex.sprite)
	{
		t->pos_x = sp[i].x - a->cam.posX + 0.5;
		t->pos_y = sp[i].y - a->cam.posY + 0.5;
		t->inv = 1.0 / (a->cam.plane_x * a->pl.dir_y - a->pl.dir_x * a->cam.plane_y);
		t->tr_x = t->inv * (a->pl.dir_y * t->pos_x - a->pl.dir_x * t->pos_y);
		t->tr_y = t->inv * (-(a->cam.plane_y) * t->pos_x + t->pos_y * a->cam.plane_x);
		t->sp_scr_x = (int)((a->win.x / 2) * (1 + t->tr_x / t->tr_y));
		ft_sprite_height(a, sp[i], t);
		i++;
	}
	free(sp);
}
