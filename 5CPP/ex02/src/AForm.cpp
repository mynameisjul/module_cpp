#include "bureaucrats.h"
#include "AForm.hpp"

// ========== SETTERS AND GETTERS
bool		AForm::getSigned() const {
	return (_signed);
}

int			AForm::getSignGrade() const {
	return (_sign_grade);
}

int			AForm::getExecGrade() const {
	return (_exec_grade);
}

std::string AForm::getName() const {
	return (_name);
}

// ========== OTHER MEMBER FUNCTIONS
void	AForm::beSigned(Bureaucrat const &i) {
	if (i.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() <= _exec_grade) {
		if (_signed == true)
			exec();
		else
			std::cout << RED << "Could not execute, form is not signed" << RESET << std::endl;
	}
	else
		throw GradeTooLowException();
}

void	AForm::exec() const {}

// ========== EXCEPTION CLASS
const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

// ========== CONSTRUCTORS AND DESTRUCTOR
AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name) {
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	_sign_grade = sign_grade;
	_exec_grade = exec_grade;
	_target = "";
	std::cout << BGRN << "[AForm] " << RESET << "Overload constructor called" << std::endl;
}

AForm::AForm(const AForm& other) {
	std::cout << BGRN << "[AForm] " << RESET << "Copy constructor called" << std::endl;
	*this = other;
}

AForm::~AForm() {
	std::cout << BRED << "[AForm] " << RESET << "Default destructor called" << std::endl;
}

AForm & AForm::operator=(const AForm& other) {
	std::cout << GRN << "[AForm] " << RESET << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_signed = other._signed;
		_sign_grade = other._sign_grade;
		_exec_grade = other._exec_grade;
	}
	return *this;
}

// =========== OSTREAM OPERATOR

std::ostream & operator<<(std::ostream &o, AForm const & i) {
	if (i.getSigned() == true)
		o << "Form name: " << i.getName() << "; status: signed; min grade to sign: " << i.getSignGrade() << "; min grade to execute: " << i.getExecGrade() << ".";
	if (i.getSigned() == false)
		o << "Form name: " << i.getName() << "; status: not signed; min grade to sign: " << i.getSignGrade() << "; min grade to execute: " << i.getExecGrade() << ".";
	return o;
}