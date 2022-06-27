#include <stdio.h>

int ft_printf(const char *s, ...);

int main(void)
{
    int p = 0;
	int	ft = 0;
    char    *s = "4224";
    int		n = 4224;
	char	*f = "s : $%s$\n";

	p = printf(f, s);
	ft = ft_printf(f, s);
	printf("p : %d\tft: %d\n", p, ft);

	f = "2s : $%2s$\n";
	p = printf(f, s);
	ft = ft_printf(f, s);
	printf("p : %d\tft: %d\n", p, ft);

	f = "8s : $%8s$\n";
	p = printf(f, s);
	ft = ft_printf(f, s);
	printf("p : %d\tft: %d\n", p, ft);

	f = "2.2s : $%2.2s$\n";
	p = printf(f, s);
	ft = ft_printf(f, s);
	printf("p : %d\tft: %d\n", p, ft);

	f = "2.8s : $%2.8s$\n";
	p = printf(f, s);
	ft = ft_printf(f, s);
	printf("p : %d\tft: %d\n", p, ft);

	f = "8.2s : $%8.2s$\n";
	p = printf(f, s);
	ft = ft_printf(f, s);
	printf("p : %d\tft: %d\n", p, ft);

	f = "8.8s : $%8.8s$\n";
	p = printf(f, s);
	ft = ft_printf(f, s);
	printf("p : %d\tft: %d\n", p, ft);
    return (0);
}