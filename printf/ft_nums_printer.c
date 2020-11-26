#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
int ft_num_zero(t_list *list, int printed)
{
	int res;
	int i;

	i = -1;
	if (list->width == 0 && list->pres == 0)
		return (0);
	if (list->width > 0 && list->pres == 0)
		while (list->width > list->pres++ && ++printed)
			write(1, " ", 1);
	return (printed);
}

