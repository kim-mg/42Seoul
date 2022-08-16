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
	
	Form(void);

public:
	Form(const std::string& name, const int& sign_grade, const int& exe_grade);
	Form(const Form& src);
	~Form(void);

	Form& operator=(const Form& src);

	const std::string& getName(void) const;
	const bool& getSigned(void) const;
	const int& getSignGrade(void) const;
	const int& getExeGrade(void) const;

	void beSigned(const Bureaucrat& b) = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif