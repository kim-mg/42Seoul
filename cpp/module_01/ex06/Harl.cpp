#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did,"
		<< "I wouldn’t be asking for more!"
		<< std::endl << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free."
		<< "I’ve been coming for years whereas you started working here since last month."
		<< std::endl << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl << std::endl;
}

void Harl::complain(std::string level) {
	std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i) {
		if (!level_arr[i].compare(level) || _flag) {
			std::cout << "[ " << level_arr[i] << " ]" << std::endl;
			(this->*f[i])();
			_flag = true;
		}
	}
	if (!_flag)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::Harl(void) 
	: _flag(false) {
}

Harl::~Harl(void) {
}