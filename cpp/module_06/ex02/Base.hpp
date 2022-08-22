#ifndef BASE_HPP
#define BASE_HPP

#include <stdint.h>
#include <cstdlib>

#include <iostream>

class Base {
public:
	virtual ~Base(void);
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif