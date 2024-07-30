#include "bureaucrats.h"
#include "PresidentialPardonForm.hpp"

// ========== OTHER MEMBER FUNCTIONS
void	PresidentialPardonForm::exec() const {
	std::cout << GRN << _target << " has been pardoned by Zaphod Beeblerox" << std::endl;
}

// ========== CONSTRUCTORS AND DESTRUCTOR
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5) {
	std::cout << BGRN << "[PresidentialPardonForm] " << RESET << "Constructor called" << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	std::cout << BGRN << "[PresidentialPardonForm] " << RESET << "Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << BRED << "[PresidentialPardonForm] " << RESET << "Default destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << GRN << "[PresidentialPardonForm] " << RESET << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}