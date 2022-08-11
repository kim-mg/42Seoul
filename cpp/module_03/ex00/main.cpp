#include "ClapTrap.hpp"

int main(void) {
	ClapTrap t1;
	ClapTrap t2("Trap 2");
	ClapTrap t3(t1);

	std::cout << std::endl;
	t1.setName("Trap 1");
	t3.setName("Trap 3");
	std::cout << std::endl;
	t2.attack("Trap 1");
	t1.takeDamage(10);
	std::cout << std::endl;
	t1.attack("Trap 2");
	t2.beRepaired(5);
	std::cout << std::endl;
	t3.attack("Trap 2");
	t2.takeDamage(0);
	t2.beRepaired(5);
	std::cout << std::endl;
	
	return 0;
}