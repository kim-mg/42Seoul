#include <iostream>

#include "Data.hpp"

int main(void) {
	Data d(100);
	uintptr_t uint_1;
	Data* ds;

	std::cout << &d << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;

	uint_1 = serialize(&d);
	std::cout << &uint_1 << std::endl;
	std::cout << uint_1 << std::endl;
	std::cout << std::endl;

	ds = deserialize(uint_1);
	std::cout << ds << std::endl;
	std::cout << *ds << std::endl;
	std::cout << std::endl;

	return 0;
}