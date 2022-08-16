#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

#define SF_SIGN	145
#define SF_EXE	137

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& name
		, const int& sign_grade, const int& exe_grade);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
};

#endif