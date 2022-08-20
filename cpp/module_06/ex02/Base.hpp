#ifndef BASE_HPP
#define BASE_HPP

#include <stdint.h>

#include <iostream>

#include "Random.hpp"

class Base {
public:
	virtual ~Base(void);
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif