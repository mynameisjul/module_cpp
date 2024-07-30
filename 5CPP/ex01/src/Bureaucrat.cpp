#include "bureaucrats.h"

// ========== GETTERS AND SETTERS

unsigned int	Bureaucrat::getGrade() const {
	return (_grade);
}

std::string		Bureaucrat::getName() const {
	return (_name);
}

void			Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void			Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

// ========== OTHER MEMBER FUNCTIONS
void		Bureaucrat::signForm(Form &f) const {
	try {
		f.beSigned(*this);
		std::cout << GRN << _name << " signed " << f.getName() << RESET << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

// ========== EXCEPTIONS
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
		return "Grade too high";
	}

// ========== CONSTRUCTORS AND DESTRUCTORS
Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << BGRN << "[Bureaucrat] " << RESET << "Overload constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << BGRN << "[Bureaucrat] " << RESET << "Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat() {
	std::cout << BRED << "[Bureaucrat] " << RESET << "Default destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << BGRN << "[Bureaucrat] " << RESET << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_grade = other._grade;
		_name = other._name;
	}
	return *this;
}

// ========== OSTREAM
std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i ) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}