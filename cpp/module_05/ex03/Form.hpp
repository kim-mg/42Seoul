#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Form {
private:
	const std::string _name;
	bool _signed;
	const int _sign_grade;
	const int _exe_grade;
	std::string _type;

public:
	Form(void);
	Form(const std::string& name, const int& sign_grade, const int& exe_grade);
	Form(const Form& src);
	virtual ~Form(void);

	Form& operator=(const Form& src);

	void setType(const std::string& type);

	const std::string& getName(void) const;
	const bool& getSigned(void) const;
	const int& getSignGrade(void) const;
	const int& getExeGrade(void) const;
	const std::string& getType(void) const;

	void beSigned(const Bureaucrat& b);

	void checkGrade(const Bureaucrat& executor) const;
	virtual void execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};

	class FormDoesNotSignedException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif