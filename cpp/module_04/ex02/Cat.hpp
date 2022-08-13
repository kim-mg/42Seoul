#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

#define C_TYPE	"Cat"
#define C_SOUND "Meow! Meow!"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat& src);
	virtual ~Cat(void);

	Cat& operator=(const Cat& src);

	const Brain* getBrain(void) const;

	virtual void makeSound(void) const;
	
private:
	Brain* _cat_brain;
};

#endif