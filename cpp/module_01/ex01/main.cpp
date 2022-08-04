#include "Zombie.hpp"

int main(void) {
	std::cout << "creates zombieHorde." << std::endl << std::endl;
	Zombie *zombies = Zombie::zombieHorde(5, Zombie::randomName());
	std::cout << std::endl << "delete zombieHorde." << std::endl << std::endl;
	delete[] zombies;
	return 0;
}
