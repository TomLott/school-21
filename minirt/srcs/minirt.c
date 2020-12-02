#include <stdio.h>
#include "../includes/minirt.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <mlx.h>

void ft_errormess(char *mess, t_mini *rt)
{
	free(rt);
	write(2, "Opening of the scene file is failed.", 36);
}

void    ft_initialize(t_mini *rt)
{
	rt->save = 0;
	rt->colour = 0;
	rt->processed = NULL;
	rt->line = NULL;
}


void	ft_parse_file(char *filename, t_mini *rt)
{
	int fd;

	if (!(fd = open(filename, O_RDONLY) < 0))
		ft_errormess("Opening of the scene file is failed.", rt);
	while(get_next_line(fd, &(rt->line)) > 0)
	{
		rt->processed = ft_setsplit(rt->line, "\n\t\v\r\f");
		if (*rt->processed)
			checker(rt);
		rt->processed = ft_mass_nullify(rt->processed);
		rt->line = ft_str_nullify(rt->line);
	}

}

int main(int argc, char **argv)
{
	t_mini  rt;

	ft_initialize(&rt);
	rt.mlx = mlx_init();
	if (argc <= 1 || argc > 3 || (argc == 3 && (ft_strcmp(argv[2], "-save"))))
	{
		// return(ft_argerror());
	}
	if (argc == 3 && ft_strcmp(argv[2], "-save") == 0)
		rt.save = 1;

	return 0;
	ft_parse_file(argv[1], &rt);
}