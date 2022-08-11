#include "ScavTrap.hpp"

int main(void) {
	ScavTrap s1;
	ScavTrap s2("SCAV 2");
	ScavTrap s3(s1);
	ScavTrap s4;

	s4 = ScavTrap("SCAV 4");
	
	std::cout << std::endl;
	s3.setName("SCAV 3");
	std::cout << std::endl;
	s1.attack(s2.getName());
	s2.takeDamage(20);
	std::cout << std::endl;
	s2.attack(s3.getName());
	s3.takeDamage(20);
	s3.beRepaired(5);
	std::cout << std::endl;
	s2.guardGate();
	s4.guardGate();
	std::cout << std::endl;

	return 0;
}