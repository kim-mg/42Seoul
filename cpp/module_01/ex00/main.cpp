#include "Zombie.hpp"

int main(void) {
	Zombie *zombie[5];

	std::cout << "1. use newZombie(heap)." << std::endl << std::endl;
	for (int i = 0; i < 5; i++) {
		zombie[i] = Zombie::newZombie(Zombie::randomName());
		zombie[i]->announce();
	}
	std::cout << std::endl << "2. use randomChump(stack)." << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
		Zombie::randomChump(Zombie::randomName());
	std::cout << std::endl << "delete heap area Zombies." << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
		delete zombie[i];
	return 0;
}
