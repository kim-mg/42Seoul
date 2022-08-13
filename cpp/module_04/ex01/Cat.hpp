#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

#define WC_TYPE	"Cat"
#define WC_SOUND "Meow! Meow!"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat& src);
	virtual ~Cat(void);

	Cat& operator=(const Cat& src);

	virtual void makeSound(void) const;
};

#endif