#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) {	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form(name, SF_SIGN, SF_EXE) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: Form(src) {
}

ShrubberyCreationForm::ShrubberyCreationForm(void) {
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	return dynamic_cast<ShrubberyCreationForm *>(Form::operator=(src));
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) {
	checkGrade(executor);
	std::ofstream ofs((getName() + "_shrubbery").c_str(),
		std::ofstream::out | std::ofstream::trunc);
	if (!ofs.good())
		throw()
	std::string shrubbery = "
														vv
												vvv^^^^vvvvv
											vvvvvvvvv^^vvvvvv^^vvvvv
									vvvvvvvvvvv^^^^^^^^^^^^^vvvvv^^^vvvvv
								vvvvvvv^^^^^^^^^vvv^^^^^^^vvvvvvvvvvv^^^vvv
							vvvv^^^^^^vvvvv^^^^^^^vv^^^^^^^vvvv^^^vvvvvv
							vv^^^^^^^^vvv^^^^^vv^^^^vvvvvvvvvvvv^^^^^^vv^
							vvv^^^^^vvvv^^^^^^vvvvv^^vvvvvvvvv^^^^^^vvvvv^
							vvvvvvvvvv^^^v^^^vvvvvv^^vvvvvvvvvv^^^vvvvvvvvv
							^vv^^^vvvvvvv^^vvvvv^^^^^^^^vvvvvvvvv^^^^^^vvvvvv
								^vvvvvvvvv^^^^vvvvvv^^^^^^vvvvvvvv^^^vvvvvvvvvv^v
									^^^^^^vvvv^^vvvvv^vvvv^^^v^^^^^^vvvvvv^^^^vvvvv
							vvvv^^vvv^^^vvvvvvvvvv^vvvvv^vvvvvv^^^vvvvvvv^^vvvvv^
							vvv^vvvvv^^vvvvvvv^^vvvvvvv^^vvvvv^v##vvv^vvvv^^vvvvv^v
							^vvvvvv^^vvvvvvvv^vv^vvv^^^^^^_____##^^^vvvvvvvv^^^^
								^^vvvvvvv^^vvvvvvvvvv^^^^/\@@@@@@\#vvvv^^^
									^^vvvvvv^^^^^^vvvvv/__\@@@@@@\^vvvv^v
										;^^vvvvvvvvvvv/____\@@@@@@\vvvvvvv
										;      \_  ^\|[  -:] ||--| | _/^^
										;        \   |[   :] ||_/| |/
										;         \\ ||___:]______/
										;          \   ;=; /
										;           |  ;=;|
										;          ()  ;=;|
										(()          || ;=;|
													/ / \;=;\\";
	ofs << shrubbery;
	ofs.close();
}