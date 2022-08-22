#include <iostream>

int main(void) {
	// int* a = new int(0);
	// int b = 1;
	int* a = new int[3];

	std::cout << a << std::endl;
	// std::cout << *a << std::endl;
	// a[0] = 1;
	// a[1] = 2;
	// a[2] = 3;
	for (int i = 0; i < 4; ++i) {
		std::cout << a[i] << std::endl;
	}

	// delete a;

	return 0;
}