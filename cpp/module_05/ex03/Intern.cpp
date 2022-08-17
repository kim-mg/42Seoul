#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {
}

Intern::Intern(const Intern& src) {
	static_cast<void>(src);
}

Intern::~Intern(void) {
}

Intern& Intern::operator=(const Intern& src) {
	static_cast<void>(src);
	return *this;
}

Form* Intern::makeForm(const std::string& form, const std::string& target) {
	const std::string forms[F_COUNT] = {F_SHRUBBERY,
										F_ROBOTOMY,
										F_PRESIDENT};
	try {
		for (int i = 0; i < F_COUNT; ++i) {
			if (forms[i] == form) {
				std::cout << "Intern creates " << form
					<< " " << target << std::endl;
				switch (i) {
					case 0:
						return new ShrubberyCreationForm(target);
						break ;
					case 1:
						return new RobotomyRequestForm(target);
						break ;
					default:
						return new PresidentialPardonForm(target);
						break ;
				}
			}
		}
		throw NoFormFindException();
	} catch (std::exception& e) {
		std::cerr << "Intern failed to create "
			<< form << " " << target
			<< " : " << e.what() << std::endl;
	}
	return 0;
}

const char* Intern::NoFormFindException::what(void) const throw() {
	return "The form does not exist";
}