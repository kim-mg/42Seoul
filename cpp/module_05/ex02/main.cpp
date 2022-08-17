#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	Bureaucrat b[3] = {Bureaucrat("Aim", 1),
						Bureaucrat("Born", 150),
						Bureaucrat("Crack", 45)};
	Form* f[3] = {new ShrubberyCreationForm("Resort"),
					new RobotomyRequestForm("Plant"),
					new PresidentialPardonForm("Loffy")};

	std::cout << b[0] << std::endl
		<< b[1] << std::endl
		<< b[2] << std::endl;
	
	for (int i = 0; i < 3; ++i) {
		std::cout << "========== Loop "
			<< i + 1 << " ==========" << std::endl;
		for (int j = 0; j < 3; ++j) {
			b[i].signForm(*(f[j]));
			b[i].executeForm(*(f[j]));
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < 3; ++i)
		delete f[i];

	return 0;
}