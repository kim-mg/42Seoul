#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

int main() {
	Bureaucrat a("A", 1);
	Bureaucrat b("B", 150);

	std::cout << a << std::endl
		<< b << std::endl;

	std::cout << std::endl
		<< "Exception Increment Decrement Test" << std::endl;
	try {
		a.incrementGrade();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		b.decrementGrade();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl
		<< "Make Instance Test" << std::endl;
	try {
		Bureaucrat c("C", 0);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat d("D", 0);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl
		<< "Copy Instance Test" << std::endl;
	try {
		Bureaucrat e(a);
		Bureaucrat f(b);

		std::cout << e << std::endl
			<< f << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl
		<< "Increment Decrement Test" << std::endl;
	try {
		for (int i = 0; i < 3; ++i) {
			a.decrementGrade();
			b.incrementGrade();

			std::cout << a << std::endl
				<< b << std::endl;
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}