#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

#define D_TYPE	"Dog"
using D_SOUND "Bark! Bark!"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog& src);
	virtual ~Dog(void);

	Dog& operator=(const Dog& src);

	virtual void makeSound(void) const;
};

#endif