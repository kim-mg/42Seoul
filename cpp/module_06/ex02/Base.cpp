#include "Base.hpp"
#include "Random.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {
}

Base* generate(void) {
	int random = Random::randNum(0, 2);
	Base* f[3] = {new A(), new B(), new C()};

	for (int i = 0; i < 3; ++i) {
		if (i != random) {
			delete f[i];
			f[i] = NULL;
		}
	}
	if (f[random])
		return f[random];
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception& e) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception& e) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception& e) {}
}