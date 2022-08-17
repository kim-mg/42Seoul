#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

#define PF_TYPE "PresidentialPardonForm"
#define PF_SIGN	25
#define PF_EXE	5

class PresidentialPardonForm : public Form {
private:
	PresidentialPardonForm(void);

public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

	void execute(const Bureaucrat& executor) const;
};

#endif