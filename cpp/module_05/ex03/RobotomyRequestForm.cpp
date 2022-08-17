#include "RobotomyRequestForm.hpp"
#include "Form.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) {
    setType(RF_TYPE);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form(target, RF_SIGN, RF_EXE) {
    setType(RF_TYPE);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: Form(src) {
    setType(RF_TYPE);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm&
	RobotomyRequestForm::operator=(const RobotomyRequestForm& src) {
	return *(dynamic_cast<RobotomyRequestForm *>(&(Form::operator=(src))));
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	static time_t tm = 0;
    int is_success = 0;
    
    if (!tm) {
        tm = std::time(0);
		std::srand(static_cast<unsigned int>(std::time(0)));
    }
    checkGrade(executor);
    is_success = std::rand() % 2;
    std::cout << "Drrrr..." << std::endl;
    if (is_success) {
        std::cout << getName() << " has been robotomized successfully"
            << std::endl;
    } else {
        std::cout << getName() << " failed to robotomized"
            << std::endl;
        throw ToolTroubleException();
    }
}

const char* RobotomyRequestForm::ToolTroubleException::what(void) const throw() {
	return "The Drill Has Broken";
}
