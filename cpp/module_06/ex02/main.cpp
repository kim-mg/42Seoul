#include <iostream>

// #include "Base.hpp"
#include "Random.hpp"

int main(void) {
	Random r;
	std::cout << r.randNum(1, 6) << std::endl;
	return 0;
}