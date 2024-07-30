#include "bureaucrats.h"
#include "Form.hpp"

// ========== SETTERS AND GETTERS
bool		Form::getSigned() const {
	return (_signed);
}

int			Form::getSignGrade() const {
	return (_sign_grade);
}

int			Form::getExecGrade() const {
	return (_exec_grade);
}

std::string Form::getName() const {
	return (_name);
}

// ========== OTHER MEMBER FUNCTIONS
void	Form::beSigned(Bureaucrat const &i) {
	if (i.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw GradeTooLowException();
}

// ========== EXCEPTION CLASS
const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

// ========== CONSTRUCTORS AND DESTRUCTOR
Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name) {
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	_sign_grade = sign_grade;
	_exec_grade = exec_grade;
	std::cout << BGRN << "[Form] " << RESET << "Overload constructor called" << std::endl;
}

Form::Form(const Form& other) {
	std::cout << BGRN << "[Form] " << RESET << "Copy constructor called" << std::endl;
	*this = other;
}

Form::~Form() {
	std::cout << BRED << "[Form] " << RESET << "Default destructor called" << std::endl;
}

Form & Form::operator=(const Form& other) {
	std::cout << GRN << "[Form] " << RESET << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_signed = other._signed;
		_sign_grade = other._sign_grade;
		_exec_grade = other._exec_grade;
	}
	return *this;
}

// =========== OSTREAM OPERATOR

std::ostream & operator<<(std::ostream &o, Form const & i) {
	if (i.getSigned() == true)
		o << "Form name: " << i.getName() << "; status: signed; min grade to sign: " << i.getSignGrade() << "; min grade to execute: " << i.getExecGrade() << ".";
	if (i.getSigned() == false)
		o << "Form name: " << i.getName() << "; status: not signed; min grade to sign: " << i.getSignGrade() << "; min grade to execute: " << i.getExecGrade() << ".";
	return o;
}