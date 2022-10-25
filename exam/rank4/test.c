#include <stdlib.h>

#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	execve(argv[1], argv + 2, envp);
	return 0;
}