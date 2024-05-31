#include "Harl.hpp"

Harl::Harl() {
	std::cout << BGRN << "Creating Harl..." << RESET << std::endl;
}

Harl::~Harl() {
	std::cout << BRED  << "Destroying Harl..." << RESET << std::endl;
}

void Harl::debug(void) {
	std::cout << CYN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;}

void Harl::warning(void) {
	std::cout << YEL << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;}

void Harl::error(void) {
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;}

void Harl::complain( std::string level ) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void (Harl::*HarlMemFn)();
	HarlMemFn ftab[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			(this->*ftab[i])();	
	}
}