#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

#define C_TYPE	"WrongCat"
#define C_SOUND "Meow! Meow!"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat& src);
	virtual ~WrongCat(void);

	WrongCat& operator=(const WrongCat& src);

	void makeSound(void) const;
};

#endif