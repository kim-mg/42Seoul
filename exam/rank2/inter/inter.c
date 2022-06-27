#include <unistd.h>
#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	cpy_c;

	ptr = (unsigned char *)b;
	cpy_c = (unsigned char)c;
	while (len > 0)
	{
		*ptr++ = cpy_c;
		len--;
	}
	return (b);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	alpha[26];

	//if (--argc < 2)
	//	exit(write(1, "\n", 1));
	// alpha = ft_memset(alpha, 0, 26);
	
	int	i;
	i = 0;
	while (i < 26)
	{
		printf("alpha[%d] : %d\n", i, alpha[i]);
		i++;
	}
	return (0);
}
