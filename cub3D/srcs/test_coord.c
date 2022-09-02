#include <stdio.h>
#include <math.h>

int	check_coord(double x1, double y1, double x2, double y2)
{
	if (fabs(floor(x2) - floor(x1)) >= 1 || fabs(floor(y2) - floor(y1)) >= 1)
		return (1);
	return (0);
}

int	main(void) {
	printf("%f\t%f", fabs(9.8), fabs(-9.8));
	check_coord(9.9, 8.9, 10, 9);
	return 0;
}