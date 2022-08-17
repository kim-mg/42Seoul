#include "PresidentialPardonForm.hpp"
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {
	setType(PF_TYPE);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form(target, PF_SIGN, PF_EXE) {
	setType(PF_TYPE);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: Form(src) {
	setType(PF_TYPE);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm&
	PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	return *(dynamic_cast<PresidentialPardonForm *>(&(Form::operator=(src))));
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	checkGrade(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox"
        << std::endl;
}
