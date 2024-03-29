#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>

class Zombie {
private:
	std::string _name;

	Zombie(void);

public:
	static Zombie* newZombie(std::string name);
	static void randomChump(std::string name);
	static std::string randomName(void);

	void announce(void) const;

	explicit Zombie(const std::string& name);
	~Zombie(void);
};

#endif