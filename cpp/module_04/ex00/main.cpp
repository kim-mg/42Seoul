#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "================ Animal ================" << std::endl;
	const Animal* meta = new Animal();
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
	std::cout << "============= Wrong Animal =============" << std::endl;

	const WrongAnimal* meta_ = new WrongAnimal();
	const WrongAnimal* i_ = new WrongCat();

	std::cout << meta_->getType() << " " << std::endl;
	std::cout << i_->getType() << " " << std::endl;
	i_->makeSound();
	meta_->makeSound();

	delete i_;
	delete meta_;

	return 0;
}