#include "../includes/cub.h"

void ft_ceiling(t_all *all, t_cam *c, t_floor *fl, int i)
{
	t_ceil *cl;

	cl = (t_ceil *)malloc(sizeof(t_ceil));
	cl->x = (int)fl->x;
	cl->y = (int)fl->y;
	fl->x += fl->step_x;
	fl->y += fl->step_y;
	my_mlx_pixel_put(all, fl->x, fl->y, 0x00000F);
}

void ft_floor(t_all *all, t_cam *c, t_dist *d, t_hight *hig)
{
	t_floor fl;
	int dist;
	int i;

	i = hig->end;
	ft_bzero(&fl, sizeof(t_floor));
	fl.ray_x0 = all->pl.dir_x - c->plane_x;
	fl.ray_y0 = all->pl.dir_y - c->plane_y;
	fl.ray_x1 = all->pl.dir_x + c->plane_x;
	fl.ray_y1 = all->pl.dir_y + c->plane_y;
	fl.pos = hig->h - all->win.y / 2; /** position if we compare pos to the screen center (hor) **/
	fl.posZ = all->win.y / 2; /** vertical pos of the camera**/
	dist = fl.posZ / fl.pos; /** dist from camera to the floor**/
	fl.step_x = dist * (fl.ray_x1 - fl.ray_x0) / all->win.x; /**real step vector that we add**/
	fl.step_y = dist * (fl.ray_y1 - fl.ray_y0) / all->win.x;
	fl.x = c->posX + (dist * fl.ray_x0);
	fl.y = c->posY + (dist * fl.ray_y0);
	ft_ceiling(all, c, &fl, i);
}