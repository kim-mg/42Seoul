#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

#define RF_TYPE "RobotomyRequestForm"
#define RF_SIGN	72
#define RF_EXE	45

class RobotomyRequestForm : public Form {
private:
	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	void execute(const Bureaucrat& executor) const;

	class ToolTroubleException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

#endif