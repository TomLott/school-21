#include "../includes/minirt.h"

void checher(t_mini *rt)
{
	if (ft_strchr(rt->processed[0], "R"))
		parse_res(rt);
	else if (ft_strcmp(rt->processed[0], "A"))
		parse_ambient(rt);
	else if (ft_strcmp(rt->processed[0], "l"))
		parse_ligth(rt);
	else if (ft_strcmp(rt->processed[0], "c"))
		parse_camera(rt);
	else if (ft_strcmp(rt->processed[0], "sp"))
		parse_sphere(rt);
	else if (ft_strcmp(rt->processed[0], "pl"))
		parse_plane(rt);
	else if (ft_strcmp(rt->processed[0], "sq"))
		parse_square(rt);
	else if (ft_strcmp(rt->processed[0], "cy"))
		parse_cylinder(rt);
	else if (ft_strcmp(rt->processed[0], "tr"))
		parse_triangle(rt);
	else if (ft_strcmp())
}