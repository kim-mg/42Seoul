#include "Form.hpp"
#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	return os << "SIGN FORM" << std::endl
		<< "NAME : " << obj.getName() << std::endl
		<< "SIGNED CHECK : " << (obj.getSigned() ? "yes" : "no") << std::endl
		<< "REQUIRED GRADE(SIGN) : " << obj.getSignGrade() << std::endl
		<< "REQUIRED GRADE(EXE) : " << obj.getExeGrade() << std::endl;
}

Form::Form(void) 
	: _name(), _signed(false), _sign_grade(0), _exe_grade(0), _type() {
}

Form::Form(const std::string& name, const int& sign_grade, const int& exe_grade)
	: _name(name), _signed(false),
		_sign_grade(sign_grade), _exe_grade(exe_grade), _type() {
	if (_sign_grade < HIGHEST_GRADE || _exe_grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (_sign_grade > LOWEST_GRADE || _exe_grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form& src)
	: _name(src.getName()), _signed(src.getSigned()), _sign_grade(src.getSignGrade())
		, _exe_grade(src.getExeGrade()) {
}

Form::~Form(void) {
}

Form& Form::operator=(const Form& src) {
	if (this != &src) {
		*(const_cast<std::string *>(&_name)) = src.getName();
		_signed = src.getSigned();
		*(const_cast<int *>(&_sign_grade)) = src.getSignGrade();
		*(const_cast<int *>(&_exe_grade)) = src.getExeGrade();
		_type = src.getType();
	}
	return *this;
}

void Form::setType(const std::string& type) {
	_type = type;
}

const std::string& Form::getName(void) const {
	return _name;
}

const bool& Form::getSigned(void) const {
	return _signed;
}

const int& Form::getSignGrade(void) const {
	return _sign_grade;
}

const int& Form::getExeGrade(void) const {
	return _exe_grade;
}

const std::string& Form::getType(void) const {
	return _type;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _sign_grade)
		throw GradeTooHighException();
	_signed = true;
}

void Form::checkGrade(const Bureaucrat& executor) const {
	if (!getSigned())
		throw FormDoesNotSignedException();
	if (executor.getGrade() > _exe_grade)
		throw GradeTooHighException();
}

const char* Form::GradeTooHighException::what(void) const throw() {
	return "Form Grade Too High";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "Form Grade Too Low";
}

const char* Form::FormDoesNotSignedException::what(void) const throw() {
	return "Form Does Not Signed";
}
