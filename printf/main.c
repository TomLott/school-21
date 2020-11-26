#include "ft_printf.h"
#include <stdio.h>

int main()
{
	/*integers 
	 *
	ft_printf("%*i", -6, -3);
	printf("-mine\n");
	printf("%*i", -6, -3);
	printf("-orig\n");
	ft_printf("%*i", -14, 94827);
	printf("-mine\n");
	printf("%*i", -14, 94827);
	printf("-orig\n");
	ft_printf("%.*i", -6, -3);
	printf("-mine\n");
	printf("%.*i", -6, -3);
	printf("-orig\n");
	ft_printf("%0*i", -7, -54);
	printf("-mine\n");
	printf("%0*i", -7, -54);
	printf("-orig\n");
	*
	ft_printf("%0*i\n", 7, -54);
	printf("%0*i", 7, -54);*/


//	ft_printf("%-*s", -32, "abc");

	printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	ft_printf("%%-5.3s LYDI == |%-5.3s|", "LYDI");
	ft_printf("%-*.*s", -7, -3, "yolo");
	printf("%%|\n");
	//printf("%-*.*s", -7, -3, "yolo");

}
