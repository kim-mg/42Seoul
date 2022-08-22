#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

class NotFindValueException : public std::exception {
public:
	const char* what(void) const throw() {
		return "Value Not Found";
	}
};

template <typename T>
typename T::iterator easyfind(T& container, const int& i) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), i);
	try {
		if (it != container.end())
			std::cout << "Easy find : " << *it << std::endl;
		else
			throw NotFindValueException();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return it;
}

#endif