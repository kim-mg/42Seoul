#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream>

#include "Form.hpp"

#define SF_SIGN	145
#define SF_EXE	137

class ShrubberyCreationForm : public Form {
private:
	ShrubberyCreationForm(void);

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

	void execute(const Bureaucrat& executor) const;
};

#endif