#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap d1("DIAMOND_1");

	std::cout << std::endl;
	d1.whoAmI();
	std::cout << std::endl;
	d1.attack("someone");
	std::cout << std::endl;

	// DiamondTrap d2("DIAMOND 2");
	// DiamondTrap d3(d2);
	// DiamondTrap d4;

	// d3.setName("DIAMOND 3");
	// d4 = DiamondTrap("DIAMOND 4");
	
	// std::cout << std::endl;
	// d3.setName("DIAMOND 3");
	// std::cout << std::endl;
	// d1.attack(f2.getName());
	// d2.takeDamage(20);
	// std::cout << std::endl;
	// d3.beRepaired(5);
	// std::cout << std::endl;
	// d2.highFivesGuys();
	// d4.highFivesGuys();
	// std::cout << std::endl;

	return 0;
}