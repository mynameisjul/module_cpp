#include "bureaucrats.h"
#include "Intern.hpp"

// ========== EXCEPTION CLASS
const char * Intern::BadFormNameException::what() const throw() {
	return "Invalid name, could not create form";
}

// ========== MEMBER FUNCTIONS
AForm	*Intern::makeForm(std::string name, std::string target) {
	if (name == "shrubbery creation") {
		std::cout << "Intern creates Shrubbery Creation form" << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (name == "robotomy request") {
		std::cout << "Intern creates Robotomy Request form" << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (name == "presidential pardon") {
		std::cout << "Intern creates Presidential Pardon form" << std::endl;
		return new PresidentialPardonForm(target);
	}
	else
		throw BadFormNameException();
}

// ========== CONSTRUCTORS AND DESTRUCTOR
Intern::Intern() {
	std::cout << BGRN << "[Intern] " << RESET << "Constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << BGRN << "[Intern] " << RESET << "Copy constructor called" << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << BRED << "[Intern] " << RESET << "Default destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << GRN << "[Intern] " << RESET << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}
