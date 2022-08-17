#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

class Form;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

	Bureaucrat(void);

public:
	Bureaucrat(const std::string& name, const int& grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat(void);

	Bureaucrat& operator=(const Bureaucrat& src);

	const std::string& getName(void) const;
	const int& getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);

	void signForm(const Form& form) const;
	void executeForm(const Form& form) const;

	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif