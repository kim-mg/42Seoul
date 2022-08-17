#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) {
	setType(SF_TYPE);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form(target, SF_SIGN, SF_EXE) {
	setType(SF_TYPE);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: Form(src) {
	setType(SF_TYPE);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	return *(dynamic_cast<ShrubberyCreationForm *>(&(Form::operator=(src))));
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	checkGrade(executor);
	std::ofstream ofs((getName() + "_shrubbery").c_str(),
		std::ofstream::out | std::ofstream::trunc);
	if (!ofs.good())
		throw FileOpenFailException();
	std::string shrubbery = "                         vv\n"
							"                     vvv^^^^vvvvv\n"
							"                 vvvvvvvvv^^vvvvvv^^vvvvv\n"
							"        vvvvvvvvvvv^^^^^^^^^^^^^vvvvv^^^vvvvv\n"
							"    vvvvvvv^^^^^^^^^vvv^^^^^^^vvvvvvvvvvv^^^vvv\n"
							"  vvvv^^^^^^vvvvv^^^^^^^vv^^^^^^^vvvv^^^vvvvvv\n"
							" vv^^^^^^^^vvv^^^^^vv^^^^vvvvvvvvvvvv^^^^^^vv^\n"
							" vvv^^^^^vvvv^^^^^^vvvvv^^vvvvvvvvv^^^^^^vvvvv^\n"
							"  vvvvvvvvvv^^^v^^^vvvvvv^^vvvvvvvvvv^^^vvvvvvvvv\n"
							"   ^vv^^^vvvvvvv^^vvvvv^^^^^^^^vvvvvvvvv^^^^^^vvvvvv\n"
							"     ^vvvvvvvvv^^^^vvvvvv^^^^^^vvvvvvvv^^^vvvvvvvvvv^v\n"
							"        ^^^^^^vvvv^^vvvvv^vvvv^^^v^^^^^^vvvvvv^^^^vvvvv\n"
							" vvvv^^vvv^^^vvvvvvvvvv^vvvvv^vvvvvv^^^vvvvvvv^^vvvvv^\n"
							"vvv^vvvvv^^vvvvvvv^^vvvvvvv^^vvvvv^v||vvv^vvvv^^vvvvv^v\n"
							" ^vvvvvv^^vvvvvvvv^vv^vvv^^^^^^_____||^^^vvvvvvvv^^^^\n"
							"    ^^vvvvvvv^^vvvvvvvvvv^^^^/\\@@@@@@\\vvvv^^^\n"
							"         ^^vvvvvv^^^^^^vvvvv/__\\@@@@@@\\^vvvv^v\n"
							"             ;^^vvvvvvvvvvv/____\\@@@@@@\\vvvvvvv\n"
							"             ;      \\_  ^\\|[  -:] ||--| | _/^^\n"
							"             ;        \\   |[   :] ||_/| |/\n"
							"             ;         \\\\ ||___:]______/\n"
							"             ;          \\   ;=; /\n"
							"             ;           |  ;=;|\n"
							"             ;          ()  ;=;|\n"
							"            (()          || ;=;|\n"
							"                        / / \\;=;\\";
	ofs << shrubbery;
	ofs.close();
}

const char* ShrubberyCreationForm::FileOpenFailException::what(void) const throw() {
	return "Lost The Form : File Open Fail";
}
