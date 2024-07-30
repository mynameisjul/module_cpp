#include "bureaucrats.h"
#include "RobotomyRequestForm.hpp"

// ========== OTHER MEMBER FUNCTIONS
void	RobotomyRequestForm::exec() const {
	std::cout << "Drrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;
	int rand = std::rand() % 2;
	if (rand == 1)
		std::cout << GRN << _target << " has been robotomized successfully" << RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed" << RESET << std::endl;
	
}

// ========== CONSTRUCTORS AND DESTRUCTOR
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45) {
	std::cout << BGRN << "[RobotomyRequestForm] " << RESET << "Constructor called" << std::endl;
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	std::cout << BGRN << "[RobotomyRequestForm] " << RESET << "Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << BRED << "[RobotomyRequestForm] " << RESET << "Default destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << GRN << "[RobotomyRequestForm] " << RESET << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}
