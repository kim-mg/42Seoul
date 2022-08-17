#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define F_COUNT		3
#define F_SHRUBBERY	"shrubbery creation"
#define F_ROBOTOMY	"robotomy request"
#define F_PRESIDENT	"presidential pardon"

class Intern {
public:
	Intern(void);
	Intern(const Intern& src);
	~Intern(void);

	Intern& operator=(const Intern& src);

	Form* makeForm(const std::string& form, const std::string& target);

	class NoFormFindException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

#endif