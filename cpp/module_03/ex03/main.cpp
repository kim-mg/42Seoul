#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap d1("DIAMOND_1");

	std::cout << std::endl;
	d1.whoAmI();
	std::cout << std::endl;
	d1.attack("someone");
	std::cout << std::endl;
	d1.printState();
	std::cout << std::endl;

	return 0;
}