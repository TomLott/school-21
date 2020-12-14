#include "../includes/cub.h"
void ft_ray(t_all *all)
{
	double degree;

	degree = (((double)all->ray.n - (all->win.x /2)) * 33)/ (all->win.x / 2);


}

void ft_screen(t_all *all)
{
	all->img.img = mlx_new_image(all->win.mlx_ptr, all->win.x, all->win.y);
	all->img.addr = (unsigned int *)mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
													  &all->img.endian);
	//missing malloc
	while(all->ray.n < all->win.x)
	{
		ft_ray(all);
	}
	
}

