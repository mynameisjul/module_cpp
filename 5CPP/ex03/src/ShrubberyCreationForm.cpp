#include "bureaucrats.h"
#include "ShrubberyCreationForm.hpp"

// ========== OTHER MEMBER FUNCTIONS
void	ShrubberyCreationForm::exec() const {
	std::string title = _target + "_shrubbery";
	std::ofstream out(title.c_str());

	out << "          &&& &&  & &&        " << " " << "          &&& &&  & &&        " << std::endl ;
	out << "      && &\\/&\\|& ()|/ @, &&   " << " " << "      && &\\/&\\|& ()|/ @, &&   " << std::endl ;
	out << "      &\\/(/&/&||/& /_/)_&/_&  " << " " << "      &\\/(/&/&||/& /_/)_&/_&  " << std::endl ;
	out << "   &() &\\/&|()|/&\\/ '%\" & ()  " << " " << "   &() &\\/&|()|/&\\/ '%\" & ()  " << std::endl ;
	out << "  &_\\_&&_\\ |& |&&/&__%_/_& && " << " " << "  &_\\_&&_\\ |& |&&/&__%_/_& && " << std::endl ;
	out << "&&   && & &| &| /& & % ()& /&&" << " " << "&&   && & &| &| /& & % ()& /&&" << std::endl ;
	out << " ()&_---()&\\&\\|&&-&&--%---()~ " << " " << " ()&_---()&\\&\\|&&-&&--%---()~ " << std::endl ;
	out << "     &&     \\|||              " << " " << "     &&     \\|||              " << std::endl ;
	out << "             |||              " << " " << "             |||              " << std::endl ;
	out << "             |||              " << " " << "             |||              " << std::endl ;
	out << "             |||              " << " " << "             |||              " << std::endl ;
	out << "       , -=-~  .-^- _         " << " " << "       , -=-~  .-^- _         " << std::endl ;
	out << "ejm97         `               " << " " << "ejm97         `               " << std::endl ;
}

// ========== CONSTRUCTORS AND DESTRUCTOR
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shruberry Creation", 145, 137) {
	std::cout << BGRN << "[ShrubberyCreationForm] " << RESET << "Constructor called" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	std::cout << BGRN << "[ShrubberyCreationForm] " << RESET << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << BRED << "[ShrubberyCreationForm] " << RESET << "Default destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << GRN << "[ShrubberyCreationForm] " << RESET << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}