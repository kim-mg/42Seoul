#include <stdio.h>

int	main(void) {
	double num;
	double cmp;
	char	arr[2][2] = {"01", "01"};

	num = 1.1 - (double)1/10;
	cmp = 1;
	if ((int)num == (int)cmp)
		printf("%f\n", num);
	else
		printf("num: %f\tcmp: %f\n", num, cmp);
	printf("%c\n", arr[(int)num][(int)cmp]);
	return (0);
}