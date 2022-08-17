#include "Form.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	Intern somRandomIntern;
	Form* rrf;
	Form* scf;
	Form* ppf;

	rrf = somRandomIntern.makeForm("robotomy request", "Bender");
	scf = somRandomIntern.makeForm("shrubbery creation", "Shilla");
	ppf = somRandomIntern.makeForm("presidential parfait", "Kid");
	ppf = somRandomIntern.makeForm("presidential pardon", "Kid");

	Bureaucrat b[3] = {Bureaucrat("Aim", 1),
						Bureaucrat("Born", 150),
						Bureaucrat("Crack", 45)};

	for (int i = 0; i < 3; ++i) {
		std::cout << "========== Loop "
			<< i + 1 << " ==========" << std::endl;
		b[i].signForm(*scf);
		b[i].executeForm(*scf);
		std::cout << std::endl;
		b[i].signForm(*rrf);
		b[i].executeForm(*rrf);
		std::cout << std::endl;
		b[i].signForm(*ppf);
		b[i].executeForm(*ppf);
		std::cout << std::endl;
	}

	delete rrf;
	delete scf;
	delete ppf;

	return 0;
}