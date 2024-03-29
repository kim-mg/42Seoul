#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* objs[6];
	Cat* kiki;

	for (int i = 0; i < 6; ++i) {
		if (i % 2)
			objs[i] = new Cat();
		else
			objs[i] = new Dog();
	}

	std::cout << std::endl;
	std::cout << std::endl;
	kiki = new Cat(*dynamic_cast<const Cat *>(objs[1]));
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 6; ++i)
		delete objs[i];
	std::cout << std::endl;
	kiki->getBrain()->showBrain();
	std::cout << std::endl;
	delete kiki;
	std::cout << std::endl;
	return 0;
}