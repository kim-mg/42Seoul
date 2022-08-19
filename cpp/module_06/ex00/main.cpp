#include <iostream>

#include "Convert.hpp"

int main(int argc, char **argv) {
	if (--argc != 1) {
		std::cerr << "usage : ./convert "
			<< "num(int, float, double)" << std::endl;
		return 1;
	}
	Convert c(argv[1]);
	c.printAll();
	return 0;
}