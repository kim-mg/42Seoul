#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <exception>

int main() {
	Bureaucrat a("A", 1);
	Bureaucrat b("B", 150);
	Bureaucrat c("C", 6);

	Form f1("One", 3, 8);
	Form f2("Two", 100, 5);
	
	std::cout << a << std::endl
		<< b << std::endl
		<< c << std::endl;
	
	std::cout << std::endl;
	std::cout << f1 << std::endl;

	a.signForm(f1);
	a.signForm(f2);	
	b.signForm(f1);
	b.signForm(f2);
	c.signForm(f1);
	c.signForm(f2);

	std::cout << std::endl;
	std::cout << f1 << std::endl;

	std::cout << std::endl
		<< "Make Instance Test" << std::endl;
	try {
		Form f3("33", 0, 100);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f4("44", 4, 161);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f5 = Form("55", 0, 10);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form f6(Form("66", 160, 10));
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}