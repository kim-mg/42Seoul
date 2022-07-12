#include <unistd.h>

int	ft_strlen(char *s)
{
	char *t;

	t = s;
	while (*t)
		t++;
	return (t - s);
}

void	error_msg(char *s)
{
	write(1, s, ft_strlen(s));
}

int	execute(FILE *file)
{
	int	scan_ret;
	
}

int	main(int argc, char *argv[])
{
	int i;
	FILE *file;

	if (--argc == 1)
	{
		file = fopen(argv[1], "r");
		if (file && !execute(file))
			return (0);
		error_msg("Error: Operation file corrupted\n");
	}
	else
		error_msg("Error: argument\n");
	return (1);
}