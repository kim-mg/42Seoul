#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "================ Animal Test 1 ================" << std::endl;
	const Animal* meta = new Dog();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "================ Animal Test 2 ================" << std::endl;

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