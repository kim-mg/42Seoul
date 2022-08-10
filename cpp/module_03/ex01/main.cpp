#include "ClapTrap.hpp"

int main(void) {
	ClapTrap t1;
	ClapTrap t2("Trap 2");
	ClapTrap t3(t1);

	t1.setName("Trap 1");
	t3.setName("Trap 3");

	t2.attack("Trap 1");
	t2.takeDamage(5);
	t2.beRepaired(5);
	t3.attack("Trap 2");
	t3.beRepaired(10);
	
	return 0;
}