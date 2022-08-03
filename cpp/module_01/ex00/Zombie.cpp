#include "Zombie.hpp"

void Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::randomName(void) {
	static time_t tm = 0;
	static std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string name(6, '\0');
	std::string::iterator start = name.begin();
	std::string::iterator end = name.end();
	
	if (!tm) {
		tm = std::time(0);
		std::srand(static_cast<unsigned int>(std::time(0)));
	}
	while (start != end)
		*start++ = alpha.at(std::rand() % 26);
	return name;
}

Zombie::Zombie(void) {
}

Zombie::Zombie(const std::string& name) : _name(name) {
}

Zombie::~Zombie(void) {
	std::cout << _name << " Died." << std::endl;
}
