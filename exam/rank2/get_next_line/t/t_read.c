#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

# define BUFFER_SIZE 5

int	ft_strlen(char *s)
{
	char	*t;

	t = s;
	if (!s)
		return (0);
	while (*t)
		t++;
	return (t - s);
}

char	*ft_strdup(char *s)
{
	char	*rtn;
	int	i;

	if (!s)
		return (NULL);
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(rtn + i) = *(s + i);
		i++;
	}
	*(rtn + i) = '\0';
	return (rtn);
}

// int	main(int argc, char *argv[])
int	main(void)
{
	char	*line;
	char	*buf;
	int	r_size;
	int	fd;
	int	i;
	int	r;

	// (void)argc;
	// (void)argv;
	// (void)line;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (1);
	line = ft_strdup("");
	// printf("%s\n", line);
	r = printf("%s\n", line);
	printf("r\t: %d\n", r);
	fd = open("f1", O_RDONLY, 0744);
	r_size = read(fd, buf, BUFFER_SIZE);
	i = 0;
	while (r_size > 0)
	{
		printf("%d\t: %d\n", i, r_size);
		i++;
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	printf("r_size\t: %d\n", r_size);
	close(fd);
	return (0);
}