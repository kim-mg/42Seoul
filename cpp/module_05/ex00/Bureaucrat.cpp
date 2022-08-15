#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	return os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
}

Bureaucrat::Bureaucrat(void) {
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
	: _name(name), _grade(grade) {
	if (_grade < HIGHEST_GRADE)
		throw(GradeTooHighException());
	if (_grade > LOWEST_GRADE)
		throw(GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: _name(src.getName()), _grade(src.getGrade()) {
}

Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src) {
	if (this != &src) {
		*(const_cast<std::string *>(&_name)) = src.getName();
		_grade = src.getGrade();
	}
	return *this;
}

const std::string& Bureaucrat::getName(void) const {
	return _name;
}

const int& Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::incrementGrade(void) {
	if (_grade <= HIGHEST_GRADE)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade(void) {
	if (_grade >= LOWEST_GRADE)
		throw GradeTooLowException();
	++_grade;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Bureaucrat Grade Too High";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Bureaucrat Grade Too Low";
}
