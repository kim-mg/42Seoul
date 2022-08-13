#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

#define D_TYPE	"Dog"
#define D_SOUND "Bowwow! Bowwow!"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog& src);
	virtual ~Dog(void);

	Dog& operator=(const Dog& src);

	const Brain* getBrain(void) const;

	virtual void makeSound(void) const;

private:
	Brain* _dog_brain;
};

#endif