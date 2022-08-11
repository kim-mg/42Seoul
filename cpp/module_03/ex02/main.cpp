#include "FragTrap.hpp"

int main(void) {
	FragTrap f1;
	FragTrap f2("FRAG 2");
	FragTrap f3(f1);
	FragTrap f4;

	f4 = FragTrap("FRAG 4");
	
	std::cout << std::endl;
	f3.setName("FRAG 3");
	std::cout << std::endl;
	f1.attack(f2.getName());
	f2.takeDamage(20);
	std::cout << std::endl;
	f3.beRepaired(5);
	std::cout << std::endl;
	f2.highFivesGuys();
	f4.highFivesGuys();
	std::cout << std::endl;

	return 0;
}