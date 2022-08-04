#include <cstring>

class Zombie {
private:
	std::string _name;

public:
	void announce(void);
	Zombie* newZombie(std::string name);

	Zombie(void);
	~Zombie(void);
}

int main(void) {

}