# include "../includes/cub.h"

int ft_player_parser(t_all *all, int i)
{
	char c;
	int j;
	int counter;

	i = 0;
	counter = 0;
	while (i < all->map.y && ++i)
	{
		j = 0;
		while (j < ft_strlen(all->map.table[i - 1]) && ++j)
		{
			c = all->map.table[i - 1][j - 1];
			if ((c == 'N' || c == 'W' || c == 'E' || c == 'S') && ++counter)
			{
				all->pl.symbol = c;
				all->pl.y = (double) i * SCALE - 0.5;
				all->pl.x = (double) j * SCALE - 0.5;
				all->pl.dir_x = (c == 'E' || c == 'W') ? 1 : 0;
				all->pl.dir_y = (c == 'S' || c == 'N') ? 1 : 0;
				all->pl.dir_x *= (c == 'W') ? -1 : 1;
				all->pl.dir_y *= (c == 'N') ? -1 : 1;
			}
		}
	}
	return (counter != 1) ? (-7) : 0;
}