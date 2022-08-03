#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>

class Zombie {
private:
	std::string _name;

public:
	static Zombie* zombieHorde(int N, std::string name);
	static std::string randomName(void);

	void setName(const std::string& name);
	void announce(void) const;

	Zombie(void);
	~Zombie(void);
};

#endif