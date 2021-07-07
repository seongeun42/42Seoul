#include <stdio.h>
#include "ft_printf.h"

int main()
{
	/*
	printf(" %d\n", printf("[%.5i]", 2));
	printf(" %d\n", ft_printf("[%.5i]", 2));
	printf(" %d\n", printf("[%08.5d]", 0));
	printf(" %d\n", ft_printf("[%08.5d]", 0));

	
	printf(" %d\n\n", printf("%0134.185i%061.174d" ,1465312329,1402026716));
	printf(" %d\n\n", ft_printf("%0134.185i%061.174d" ,1465312329,1402026716));

	printf("[%15.*s]\n", -5, "0123456789");
	printf("[%15.3s]\n", "0123456789");
	printf("[%5.*s]\n", -5, "0123456789");
	printf("[%5.3s]\n", "0123456789");
	*/

	/*
	printf("[%.*d]\n", -5, 0);
	ft_printf("[%.*d]\n", -5, 0);
	printf("[%.0d]\n", 0);
	ft_printf("[%.0d]\n", 0);
	printf("[%.d]\n", 0);
	ft_printf("[%.d]\n", 0);

	printf("[%0+u]\n", 123);
	printf("[%0 u]\n", 123);
	*/

	/*
	ft_printf("[%#x]\n", 123);
	printf("[%#x]\n", 123);
	ft_printf("[%#X]\n", 123);
	printf("[%#X]\n", 123);
	ft_printf("[%.*d]\n", 10, -2);
	printf("[%.*d]\n", 10, -2);
	ft_printf("[%.0d]\n", 0);
	printf("[%.0d]\n", 0);
	*/

	ft_printf("[%#.1x]\n", 42);
	printf("[%#010.*x]\n", -5, 42);

	return (0);
}
