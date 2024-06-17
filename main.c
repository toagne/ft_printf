#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char *str = "ciao";
	int len_printf;
	int len_ft_printf;

	len_printf = printf("%c %s %d %i %u %% %p %x %X", 'a', "ciao", 2147483647, -7, -1, str, 1000, 1000);
	printf(" = printf");
	printf("\n = ft_printf");
	len_ft_printf = ft_printf("%c %s %d %i %u %% %p %x %X", 'a', "ciao", 2147483647, -7, -1, str, 1000, 1000);
	printf("\nlen_printf = %d\n", len_printf);
	printf("len_ft_printf = %d\n", len_ft_printf);
//	printf("\n%d\n", ft_printf(0));
//	printf("\n%d\n", printf(0));
}
