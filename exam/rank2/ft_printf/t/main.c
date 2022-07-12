#include <stdio.h>

int	ft_printf(const char *s, ...);

int	main(void)
{
	unsigned int un;

	(void)un;
	un = -2147483648;
	ft_printf("%x\n", un);
	printf("%x", (int)-2147483648);
	return (0);
}