#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {
}

Base* generate(void) {
	static int seed = 0;
	int random = 0;
	Base* f[3] = {new A(), new B(), new C()};

	if (!seed) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seed = 1;
	}
	random = std::rand() % 3;
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
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	} catch (std::exception& e) {}
	try {
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
	} catch (std::exception& e) {}
	try {
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
	} catch (std::exception& e) {}
}